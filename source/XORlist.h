#include <new>
#include <iostream>
#include <cstdlib>

template<typename T>
class list {
private:
	struct node {
		T data;
		node* ptr;
	};
	node* getNext(node* prev, node* now);
	node* getPrev(node* now, node* next);
	long long int _length;
	bool _isLength;
	node* _firstNode;
	node* _lastNode;
	void count();

public:
	list();
	~list();
	//T get(long long int idx);
	//T operator[](long long int idx);
	void push_back(T data);
	void push_front(T data);
	void pop_back();
	void pop_front();
	long long int length();

	void printList();
};
