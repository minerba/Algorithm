#include<iostream>
#define N 10001
using namespace std; 

int arr[N], num[100001]; 
int mmax; 

int m_max(int a, int b){
	return a > b ? a : b; 
}

int main(){
	for (int i = 0; i < 10; i++){
		cin >> arr[i];
		num[arr[i]]++; 
		mmax = m_max(mmax, arr[i]); 
	}
	for (int i = 0; i < mmax; i++){
		if (num[i]){
			for (int j = 0; j < num[i]; j++){
				cout << i << ' ';
			}
		}
	}
	cout << '\n'; 
	return 0; 
}