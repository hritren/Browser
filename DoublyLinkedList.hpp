#pragma once
#include<iostream>
#include<ctime>

using namespace std;

template<typename T>
class DoublyLinkedList {
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList<T>& other);
	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);
	bool empty() const;
	void pushBack(const T& el);
	void pushFront(const T& el);
	void insertAt(const T& el, size_t index);
	void updateAt(const T& el, size_t index);
	T popBack();
	T popFront();
	T removeAt(size_t index);
	void print() const;
	void print(size_t current) const;
	size_t size() const;
private:
	struct Node {
		Node(T data) : data(data) {}
		T data;
		Node* next = nullptr;
		Node* prev = nullptr;
	};
	size_t count;
	Node* start;
	Node* end;
	void Free();
	void CopyFrom(const DoublyLinkedList& other);
	void getAtIndex(size_t index, Node*& ptr);
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
	start = end = nullptr;
	count = 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
	Free();
}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other){
	CopyFrom(other);
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other){
	if (*this != other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

template<typename T>
inline bool DoublyLinkedList<T>::empty() const{
	return (count == 0);
}

template<typename T>
void DoublyLinkedList<T>::pushBack(const T& el) {
	Node* newEl = new Node(el);
	if (empty()) {
		start = end = newEl;
		count++;
		return;
	}
	count++;
	end->next = newEl;
	newEl->prev = end;
	end = newEl;
}

template<typename T>
void DoublyLinkedList<T>::pushFront(const T& el) {
	Node* newEl = new Node(el);
	if (empty()) {
		start = end = newEl;
		count++;
		return;
	}
	newEl->next = start;
	start->prev = newEl;
	start = newEl;
	count++;
}

template<typename T>
void DoublyLinkedList<T>::insertAt(const T& el, size_t index) {
	if (index > count)
		throw "invalid index";
	if (index == 0) {
		pushFront(el);
		return;
	}
	if (index == count) {
		pushBack(el);
		return;
	}
	Node* ptr;
	getAtIndex(index, ptr);
	Node* newEl = new Node(el);
	newEl->next = ptr;
	newEl->prev = ptr->prev;
	ptr->prev->next = newEl;
	ptr->prev = newEl;
	count++;
}

template<typename T>
void DoublyLinkedList<T>::updateAt(const T& el, size_t index) {
	if (index >= count)
		throw "Invalid index!";
	Node* ptr = start;
	getAtIndex(index, ptr);
	ptr->data = el;
}

template<typename T>
T DoublyLinkedList<T>::popBack() {
	if (empty())
		throw "Empty!";
	if (start == end) {
		T data = start->data;
		delete start;
		start = end = nullptr;
		return data;
	}
	T data = end->data;
	end->prev->next = nullptr;
	Node* toDelete = end;
	end = end->prev;
	delete toDelete;
	count--;
	return data;
}

template<typename T>
T DoublyLinkedList<T>::popFront() {
	if (empty())
		throw "Empty!";
	if (start == end) {
		T data = start->data;
		delete start;

		start = end = nullptr;

		count--;
		return data;
	}
	T data = start->data;
	start->next->prev = nullptr;
	Node* toDelete = start;
	start = start->next;
	delete toDelete;
	count--;
	return data;
}

template<typename T>
T DoublyLinkedList<T>::removeAt(size_t index) {
	if (index >= count)
		throw "Invalid index!";
	if (empty())
		throw "Empty!";
	if (index == 0)
		return popFront();
	if (index == count - 1)
		return popBack();
	Node* toRemove;
	getAtIndex(index, toRemove);
	T data = toRemove->data;
	toRemove->prev->next = toRemove->next;
	toRemove->next->prev = toRemove->prev;
	delete toRemove;
	count--;
	return data;
}

template<typename T>
void DoublyLinkedList<T>::print() const {
	Node* iter = start;
	for (size_t i = 0; i < count; i++)
	{
		cout << iter->data << endl;
		iter = iter->next;
	}
}

template<typename T>
void DoublyLinkedList<T>::print(size_t current) const {
	Node* iter = start;
	for (size_t i = 0; i < count; i++)
	{
		if (current == i) {
			cout << "> ";
		}
		cout << iter->data << endl;
		iter = iter->next;
	}
}

template<typename T>
size_t DoublyLinkedList<T>::size() const {
	return count;
}

template<typename T>
inline void DoublyLinkedList<T>::Free() {
	Node* iter = start;
	while (iter != nullptr)
	{
		Node* toDelete = iter;
		iter = iter->next;
		delete toDelete;
	}
}

template<typename T>
inline void DoublyLinkedList<T>::CopyFrom(const DoublyLinkedList& other) {
	Node* otherIter = other.start;
	while (otherIter != nullptr) {
		pushBack(otherIter->data);
		otherIter = otherIter->next;
	}
}

template<typename T>
void DoublyLinkedList<T>::getAtIndex(size_t index, Node*& ptr) {
	Node* iter = start;
	for (size_t i = 0; i < index; i++) {
		iter = iter->next;
	}
	ptr = iter;
}