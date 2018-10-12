#include<iostream>
using namespace std; 

class Node {
public:
	int data; 
	Node* tail; 
};

class SLL {
public:
	Node *headLink; 
	Node *tempLink; 
	
	SLL() {
		headLink = NULL; 
	}

	void CreateFirst(int data) {
		Node *tmp = new Node(); 
		tmp->data = data; 
		tmp->tail = headLink; 
		headLink = tmp; 
	}

	void Print() {
		tempLink = headLink; 
		while (tempLink->tail != NULL) {
			cout << tempLink->data << " -> "; 
			tempLink = tempLink->tail; 
		}
		cout << tempLink->data << '\n'; 
	}
};

int main() {
	SLL *list = new SLL(); 
	for (int i = 0; i < 6; i++) {
		int x; cin >> x; 
		list->CreateFirst(x); 
	}

	list->Print(); 
	return 0; 
}