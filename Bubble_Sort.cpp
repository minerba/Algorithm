#include<iostream>

using namespace std; 

template<class T>
class _vector {
public:
	int _size; 
	int capacity; 
	T *arr; 
	_vector() {
		_size = 0; 
		capacity = 32; 
		arr = new T[capacity]; 
	}
	
	_vector(int k) {
		_size = k; 
		capacity = k; 
		arr = new T[k]; 
	}
};


int main() {


	return 0; 
}