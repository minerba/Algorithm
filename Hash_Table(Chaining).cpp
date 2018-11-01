// =====================================================================================
// 
//       Filename:  Hash_Table(Chaining).cpp
//        Created:  2018년 11월 01일 15시 34분 05초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  Minerba ,  proability@naver.com
//        Company:  ChungBuk University
// 
// =====================================================================================
#pragma once
#include<iostream>
#define MAX_SIZE      10
#define HASH_KEY(hash_key)  hash_key%MAX_SIZE
using namespace std;

class Node {
public:
	int data;
	Node *nextNode;
};

Node *hashTable[MAX_SIZE];

void AddNode(int data, Node *node) {
	int hash_key = HASH_KEY(data);

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

	if (hashTable[hash_key] == NULL) {
		return;
	}
	Node *delNode = new Node();
	if (hashTable[hash_key]->data == data) {
		delNode = hashTable[hash_key];
		hashTable[hash_key] = hashTable[hash_key]->nextNode;
	}
	else {
		Node *node = hashTable[hash_key];
		Node *nxt = node->nextNode;
		while (nxt) {
			if (nxt->data == data) {
				delNode = nxt;
				node->nextNode = nxt->nextNode;
				break;
			}
			node = nxt;
			nxt = nxt->nextNode;
		}
	}
	free(delNode);
}


int main() {
	int n;
	cout << "데이터의 갯수 입력 : ";
	cin >> n;

	cout << "데이터를 입력하세요 : ";

	for (int i = 0; i < n; i++) {
		int x;  cin >> x;
		Node *node = new Node();
		node->data = x; node->nextNode = NULL;
		AddNode(x, node);
	}
	cout << "현재 테이블 현황 ";
	for (int i = 0; i < MAX_SIZE; i++) {
		cout << "table No " << i << '\n';
		Node *search = hashTable[i];
		while (search) {
			cout << search->data << ' ';
			search = search->nextNode;
		}
		cout << '\n' << '\n';
	}

	int delQuery;
	cout << "삭제 연산 수를 입력하세요 : ";
	cin >> delQuery;
	cout << "삭제할 데이터를 입력하세요 : ";
	while (delQuery--) {
		int x; cin >> x;
		DelNode(x);
	}

	cout << "현재 테이블 현황 ";
	for (int i = 0; i < MAX_SIZE; i++) {
		cout << "table No " << i << '\n';
		Node *search = hashTable[i];
		while (search) {
			cout << search->data << ' ';
			search = search->nextNode;
		}
		cout << '\n' << '\n';
	}

	return 0;
}