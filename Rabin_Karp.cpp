#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int n, m; string s; vector<int> ans;


void find(string parent, string pattern) {
	int parent_sz = parent.size();
	int pattern_sz = pattern.size();

	int Hash_parent = 0, Hash_pattern = 0, finger = 1;
	for (int i = 0; i <= parent_sz - pattern_sz; i++) {
		if (i == 0) {
			for (int j = 0; j < pattern_sz; j++) {
				Hash_parent += (parent[pattern_sz - 1 - j] * finger);
				Hash_pattern += (pattern[pattern_sz - 1 - j] * finger);
				if (j < pattern_sz - 1) finger *= 2;
			}
		}
		if (Hash_parent != Hash_pattern)
			Hash_parent = 2 * (Hash_parent - parent[i] * finger) + parent[pattern_sz - 1 + i];
		else {
			bool finded = true;
			for (int j = 0; j < pattern_sz; j++) {
				if (pattern[j] != parent[i + j]) {
					finded = false;
					break;
				}
			}
			if (finded)
				ans.push_back(i + 1);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string parent;  string pattern;
	getline(cin, parent); getline(cin, pattern);
	find(parent, pattern);
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}