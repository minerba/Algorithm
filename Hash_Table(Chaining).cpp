// =====================================================================================
// 
//       Filename:  Hash_Table(Chaining).cpp
//        Created:  2018년 11월 01일 15시 34분 05초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  Minerba ,  proability@naver.com
//        Company:  ChungBuk University
// 
// =====================================================================================
#include<iostream>

#define MAX_HASH 10
#define HASH_KEY(key) key%MAX_HASH

using namespace std; 
class Node {
public:
	int data; 
	Node *nextNode; 
};
Node *hashTable[MAX_HASH]; 

void AddHash(int id, Node *node) {
	int hash_key = HASH_KEY(id); 
	if (hashTable[hash_key] == NULL) {
		hashTable[hash_key] = node; 
	}
	else {
		node->nextNode = hashTable[hash_key]; 
		hashTable[hash_key] = node; 
	}
}

void DelNode(int data) {
	int hash_key = HASH_KEY(data); 
	if (hashTable[hash_key] == NULL)
		return; 
	Node *delNode = NULL; 

	if (hashTable[hash_key]->data == data) {
		delNode = hashTable[hash_key]; 
		hashTable[hash_key] = hashTable[hash_key]->nextNode; 
	}
	else {
		Node *node = hashTable[hash_key]; 
		Node *nxt = node->nextNode; 
		while (nxt) {
			if (nxt->data == data) {
				node->nextNode = nxt->nextNode; 
				delNode = nxt; 
				break; 
			}
			node = nxt; 
			nxt = nxt->nextNode; 
		}
	}
	free(delNode); 
}

int main() {
	int n; cin >> n; 

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		Node *node = new Node(); 
		node->data = x; 
		node->nextNode = NULL; 
		AddHash(x, node); 
	}
	for (int i = 0; i < MAX_HASH; i++) {
		cout << i << '\n'; 
		Node *tmp = hashTable[i]; 
		while (tmp) {
			cout << tmp->data << ' '; 
			tmp = tmp->nextNode; 
		}
		cout << '\n'; 
	}
	return 0; 
}