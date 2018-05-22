#include "XORlist.h"

template<typename T>
typename list<T>::node* list<T>::getNext(node* prev, node* now) {
	if (!now || !(now->ptr)) return 0;
	return (list<T>::node*)((long long int)prev ^ (long long int)now->ptr);
}

template<typename T>
typename list<T>::node* list<T>::getPrev(node* now, node* next) {
	if (!now || !(now->ptr)) return 0;
	return (list<T>::node*)((long long int)now->ptr ^ (long long int)next);
}

template<typename T>
list<T>::list() { //생성자 
	list<T>::_lastNode = 0;
	list<T>::_firstNode = 0;
	_length = 0;
	_isLength = 1;
}

template<typename T>
list<T>::~list() { //소멸자 
	if (_firstNode) {
		list<T>::node* prev = 0;
		list<T>::node* now = _firstNode;
		do {
			list<T>::node* next = list<T>::getNext(prev, now);
			prev = now; now = next;
			delete next;
		} while (now != _lastNode && now);
	}
}

template<typename T>
void list<T>::count() {
	if (!_firstNode) {
		_length = 0;
		_isLength = 1;
	}
	else {
		list<T>::node* prev = 0;
		list<T>::node* now = _firstNode;
		_length = 1;
		while (now && now != _lastNode) {
			list<T>::node* next = list<T>::getNext(prev, now);
			prev = now; now = next;
			_length++;
		}
		_isLength = 1;
	}
}

template<typename T>
long long int list<T>::length() {
	if (!_isLength) count();
	return _length;
}

/*template<typename T>
T get(long long int idx){

}*/

template<typename T>
void list<T>::push_back(T data) {
	_length++;
	list<T>::node* newNode = new list<T>::node();
	newNode->data = data;
	newNode->ptr = 0;
	if (_lastNode) {
		list<T>::node* prev = list<T>::getPrev(_lastNode, 0);
		_lastNode->ptr = (list<T>::node*)((long long int)prev ^ (long long int)newNode);
		newNode->ptr = _lastNode;
		_lastNode = newNode;
	}
	else {
		_firstNode = newNode;
		_lastNode = _firstNode;
	}
}

template<typename T>
void list<T>::push_front(T data) {
	_length++;
	list<T>::node* newNode = new list<T>::node();
	newNode->data = data;
	newNode->ptr = 0;
	if (_firstNode) {
		_firstNode->ptr = (list<T>::node*)((long long int)newNode ^ (long long int)_firstNode->ptr);
		newNode->ptr = _firstNode;
		_firstNode = newNode;
	}
	else {
		_firstNode = newNode;
		_lastNode = _firstNode;
	}
}

template<typename T>
void list<T>::pop_back() {
	if (!_isLength) count();
	if (!_length) {
		std::cout << "underflow :( \n";
		exit(1);
	}

	if (_length == 1) {
		delete _lastNode;
		_lastNode = 0;
		_firstNode = 0;
		_length--;
		return;
	}
	else {
		list<T>::node* poped = _lastNode;
		list<T>::node* prev = list<T>::getPrev(poped, 0);
		prev->ptr = (list<T>::node*)((long long int)prev->ptr ^ (long long int)poped);
		_lastNode = prev;
		delete poped;
		_length--;
	}
}

template<typename T>
void list<T>::pop_front() {
	if (!_isLength) count();
	if (!_length) {
		std::cout << "underflow :( \n";
		exit(1);
	}

	if (_length == 1) {
		_length--;
		delete _firstNode;
		_firstNode = 0;
		_lastNode = 0;
		return;
	}
	else {
		list<T>::node* poped = _firstNode;
		list<T>::node* next = list<T>::getNext(0, poped);
		next->ptr = (list<T>::node*)((long long int)next->ptr ^ (long long int)poped);
		_firstNode = next;
		_length--;
		delete poped;
	}
}

template<typename T>
void list<T>::printList() {
	list<T>::node* prev = 0;
	list<T>::node* now = _firstNode;
	list<T>::node* next;
	std::cout << "print list..." << std::endl;
	while (now != NULL) {
		next = list<T>::getNext(prev, now);
		std::cout << now->data << std::ends;
		prev = now; now = next;
	}
}
