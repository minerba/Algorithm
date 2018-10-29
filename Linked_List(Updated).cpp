#include<iostream>

using namespace std; 

class Node {
public:
	int data[5]; 
	Node *nextNode; 
};

class SLL {
public:
	Node *headLink; 
	Node *tempLink;

	SLL() {
		headLink = NULL; 
	}

	void createFirst(int data[]) {
		Node *tmp = new Node(); 
		for (int j = 0; j < 4; j++) 
			tmp->data[j] = data[j]; 
		tmp->nextNode = headLink; 
		headLink = tmp; 
		ListSize++; 
	}

	const int getSize() {
		return ListSize; 
	}

private:
	int ListSize = 0; 
};


int main() {
	SLL *list = new SLL(); 
	
	for (int i = 0; i < 6; i++) {
		int x[5]; 
		for (int j = 0; j < 4; j++) 
			cin >> x[j];
		list->createFirst(x); 
	}
	Node *tmp = list->headLink;
	cout << "리스트의 사이즈 : " << list->getSize() << '\n'; 
	while (tmp->nextNode != NULL) {
		for (int j = 0; j < 4; j++) 
			cout << tmp->data[j] << ' '; 
		cout << '\n'; 
		tmp = tmp->nextNode; 
	}
	for (int j = 0; j < 4; j++)
		cout << tmp->data[j] << ' ';
	
	return 0; 
}