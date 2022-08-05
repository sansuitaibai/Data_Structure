#pragma once
#ifndef _HEADSINGLECIRLELIST_H_
#define _HEADSINGLECIRLELIST_H_
#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

template<typename E>
struct Node {
	E element;
	Node<E>* next;

public:
	Node() {
		next = nullptr;
	}
	Node(E e, Node<E>* p) {
		this->element = e;
		this->next = p;
	}
};

template<typename E>
class HeadSingleCircleList {
private:
	Node<E>* first;
	int count;
public:
	static const int ELEMENT_NOT_FOUND;
public:
	//构造/析构函数
	HeadSingleCircleList();
	HeadSingleCircleList(int c, Node<E>* p);
	~HeadSingleCircleList();


	//普通函数
	void clear();
	int size();
	bool isEmpty();
	bool contains(const E& element);

	void push_front(const E& element);
	void push_back(const E& element);
	int indexOf(const int& element);
	Node<E>* node(const int& index); //获取index位置节点，并返回指针
	void insert(const int& index, const E& element); //在index位置处插入元素element

	E pop_front();
	E pop_back();
	E remove(const int& index);//将index位置处的元素删除并且返回该值

	E get(const int& index);
	E set(const int& index, const E& element);


	void printSingList();
private:
	void outOfRang(const string& s);
	void rangCheck(const int& index);
	void rangCheckForAdd(const int& index);

};


template<typename E>
const int HeadSingleCircleList<E>::ELEMENT_NOT_FOUND = -1;

template<typename E>
void HeadSingleCircleList<E>::outOfRang(const string& s) {
	std::cout << s << std::endl;

}

template<typename E>
void HeadSingleCircleList<E>::rangCheck(const int& index) {
	if (index < 0 || index >= this->count)
		this->outOfRang("index <0 || index >= count");
}

template<typename E>
void HeadSingleCircleList<E>::rangCheckForAdd(const int& index) {
	if (index < 0 || index > this->count)
		this->outOfRang("index < 0 || index > count ");
}


//构造/析构函数
template<typename E>
HeadSingleCircleList<E>::HeadSingleCircleList() {
	this->count = 0;
	this->first = nullptr;
	this->first = new Node<E>(E(), nullptr);
	if (this->first == nullptr)
		abort();
}

template<typename E>
HeadSingleCircleList<E>::HeadSingleCircleList(int c, Node<E>* p) {
	this->count = c;
	this->first = p;
	if (this->first == nullptr) {

		this->count = 0;
		this->first = new Node<E>(E(), nullptr);
		if (this->first == nullptr)
			abort();
	}
	
}

template<typename E>
HeadSingleCircleList<E>::~HeadSingleCircleList() {
	this->clear();
}


//普通函数
template<typename E>
void HeadSingleCircleList<E>::clear() {
	int n = this->count; 
	Node<E>* current = this->first->next;
	while (n--) {
		Node<E>* tmp = current;
		current = current->next;
		delete tmp;
	}
	this->count = 0;
	delete this->first;
	this->first = nullptr;
}

template<typename E>
int HeadSingleCircleList<E>::size() {

	return this->count;
}

template<typename E>
bool HeadSingleCircleList<E>::isEmpty()
{

	return this->count == 0;

}

template<typename E>
bool HeadSingleCircleList<E>::contains(const E& element) {

	return this->indexOf(element) != this->ELEMENT_NOT_FOUND;
}


template<typename E>
void HeadSingleCircleList<E>::push_front(const E& element) {

	this->insert(0, element);

}


template<typename E>
void HeadSingleCircleList<E>::push_back(const E& element) {

	this->insert(this->count, element);
}


template<typename E>
int HeadSingleCircleList<E>::indexOf(const int& element) {

	Node<E>* current = this->first->next;
	for (int i = 0; i < this->count; ++i) {
		if (element == current->element) return i;
	}

	return this->ELEMENT_NOT_FOUND;

}


template<typename E>
Node<E>* HeadSingleCircleList<E>::node(const int& index) //获取index位置节点，并返回指针
{
	this->rangCheck(index);
	Node<E>* current = this->first->next; 
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}

	return current;
}




template<typename E>
void HeadSingleCircleList<E>::insert(const int& index, const E& element) //在index位置处插入元素element
{
	this->rangCheckForAdd(index);
	if (index == 0) {
		Node<E>* prev = this->first;
		Node<E>* newnode = new Node<E>(element, prev->next);
		Node<E>* last = (this->count == 0) ? newnode : this->node(this->count- 1);
		last->next = newnode;
		prev->next = newnode;
		
		
	}
	else {
		Node<E>* prev = this->node(index - 1);
		Node<E>* newnode = new Node<E>(element, prev->next);
		prev->next = newnode;
	}
	
	++this->count;
}

template<typename E>
E HeadSingleCircleList<E>::pop_front() {

	if (this->count == 0)
		abort();
	return this->remove(0);

}

template<typename E>
E HeadSingleCircleList<E>::pop_back()
{
	if (this->count == 0)
		abort();
	return this->remove(this->count - 1);


}

template<typename E>
E HeadSingleCircleList<E>::remove(const int& index)//将index位置处的元素删除并且返回该值
{
	this->rangCheck(index);
	Node<E>* node = first->next;
	if (index == 0) {
		
		
		if (this->count == 1) {
			first->next = nullptr;
		}
		else {
			Node<E>* last = this->node(this->count - 1);
			first->next  = node->next;
			last->next = first->next;
		}
		
		
		
	}
	else {
		Node<E>* prev = this->node(index - 1);
		node = prev->next;
		prev->next = node->next;
	}
	E ret = node->element;
	delete node;
	--this->count;
	return ret;


}

template<typename E>
E HeadSingleCircleList<E>::get(const int& index) {


	return this->node(index)->element;

}



template<typename E>
E HeadSingleCircleList<E>::set(const int& index, const E& element) {

	Node<E>* node = this->node(index);
	E ret = node->element;
	node->element = element;
	return ret;


}


template<typename E>
void HeadSingleCircleList<E>::printSingList() {
	Node<E>* current = first->next;
	int n = this->count;
	while (n--) {
		std::cout << current->element << " -> ";
		current = current->next;
	}
	std::cout << current->element << std::endl;
}




#endif // !_HEADSINGLECIRLELIST_H_
