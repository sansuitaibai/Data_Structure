#ifndef _DOUBLECIRCLELIST_H_
#define _DOUBLECIRCLELIST_H_
#include<iostream>
#include<string>
#include<stdexcept>


template<typename E> 
struct Node {
public:
	E element;
	Node<E>* prev;
	Node<E>* next;

public:
	Node(Node<E>* p, E e, Node<E>* n) {
		this->prev = p;
		this->next = n;
		this->element = e;
	}
	Node() {
		this->element = E();
		this->prev = nullptr;
		this->next = nullptr;
	}
};


template<typename E>
class DoubleCircleList {
private:
	int count;
	Node<E>* first;
	Node<E>* last;
	
public:
	static const int ELEMENT_NOT_FOUND;
public:
	DoubleCircleList(const int& c, Node<E>* f, Node<E>l);
	DoubleCircleList();
	~DoubleCircleList();
private:
	void outOfRang(const std::string& s);
	void rangCheck(const int& index);
	void rangCheckForAdd(const int& index);

public:
	int size();
	bool isEmpty();
	void clear();
	bool contains(const E& element);
	int indexOf(const E& element);

	E front();
	E back();
	E get(const int& index);
	E set(const int& index, const E& element);


	void push_front(const E& element);
	void push_back(const E& element);
	Node<E>* node(const int& index);
	void insert(const int& index, const E& element);

	E pop_front();
	E pop_back();
	E remove(const int& index);

	void printDoubleCircleList();






};

template<typename E>
const int DoubleCircleList<E>::ELEMENT_NOT_FOUND = -1;

template<typename E>
DoubleCircleList<E>::DoubleCircleList(const int& c, Node<E>* f, Node<E>l) {
	this->count = c;
	this->first = f;
	this->last = l;
}

template<typename E>
DoubleCircleList<E>::DoubleCircleList() {
	this->first = nullptr;
	this->last = nullptr;
	this->count = 0;
}
template<typename E>
DoubleCircleList<E>::~DoubleCircleList() {
	this->clear();
}

template<typename E>
void DoubleCircleList<E>::outOfRang(const std::string& s) {
	throw std::out_of_range(s);
}



template<typename E>
void DoubleCircleList<E>::rangCheck(const int& index) {
	if (index < 0 || index >= this->count)
		this->outOfRang("rangCheck index < 0 || index >= this->count");
}



template<typename E>
void DoubleCircleList<E>::rangCheckForAdd(const int& index) {
	if (index < 0 || index > this->count)
		this->outOfRang("rangCheckForAdd index < 0 || index > this->count");
}




template<typename E>
int DoubleCircleList<E>::size() {
	return this->count;

}
template<typename E>
bool DoubleCircleList<E>::isEmpty() {

	return this->count == 0;
}


template<typename E>
void DoubleCircleList<E>::clear() {

	int n = this->count;
	Node<E>* current = first;
	Node<E>* temp = nullptr;
	while (n--) {
		temp = current;
		current = current->next;
		delete temp;
	}
	this->first = nullptr;
	this->last = nullptr;
	this->count = 0;

}



template<typename E>
bool DoubleCircleList<E>::contains(const E& element) {

	return this->indexOf(element) != this->ELEMENT_NOT_FOUND;

}



template<typename E>
int DoubleCircleList<E>::indexOf(const E& element) {

	Node<E>* current = this->first;
	for (int i = 0; i < this->count; ++i) {
		if (current->element == element) return i;
		current = current->next;
	}
	return this->ELEMENT_NOT_FOUND;

}



template<typename E>
E DoubleCircleList<E>::front() {

	return this->get(0);

}


template<typename E>
E DoubleCircleList<E>::back() {

	return this->get(this->count - 1);

}


template<typename E>
E DoubleCircleList<E>::get(const int& index) {
	this->rangCheck(index);
	Node<E>* current = first;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->element;

}


template<typename E>
E DoubleCircleList<E>::set(const int& index, const E& element) {

	Node<E>* node = this->node(index);
	E ret = node->element;
	node->element = element;
	return ret;

}



template<typename E>
void DoubleCircleList<E>::push_front(const E& element) {

	this->insert(0, element);


}


template<typename E>
void DoubleCircleList<E>::push_back(const E& element) {

	this->insert(this->count, element);
}


template<typename E>
Node<E>* DoubleCircleList<E>::node(const int& index) {
	this->rangCheck(index);
	Node<E>* node = first;
	for (int i = 0; i < index; ++i) {
		node = node->next;
	}
	return node;
}



template<typename E>
void DoubleCircleList<E>::insert(const int& index, const E& element) {
	this->rangCheckForAdd(index);
	
	if (this->count == index) {
		Node<E>* oldlast = last;
		last = new Node<E>(oldlast, element, first);
		if (oldlast == nullptr) {
			last->prev = last;
			last->next = last;
			first = last;
		}
		else {
			oldlast->next = last;
			first->prev = last;
		}
	}
	else {

		Node<E>* next = this->node(index);
		Node<E>* prev = next->prev;
		Node<E>* newnode = new Node<E>(prev, element, next);
		
		if (prev == this->last) {
			this->first = newnode;
		}
		prev->next = newnode;
		next->prev = newnode;
	}

	++this->count;


}




template<typename E>
E DoubleCircleList<E>::pop_front() {

	return this->remove(0);

}



template<typename E>
E DoubleCircleList<E>::pop_back() {

	return this->remove(this->count - 1);

}



template<typename E>
E DoubleCircleList<E>::remove(const int& index) {
	this->rangCheck(index);
	Node<E>* node = this->node(index);
	Node<E>* prev = node->prev;
	Node<E>* next = node->next;
	
	if (this->count == 1) {
		this->first = nullptr;
		this->last = nullptr;
	}
	else {
		prev->next = next;
		next->prev = prev;
		if (index == 0){
			this->first = next;
		}
		if (index == this->count - 1) {
			this->last = prev;
		}
	}
	
	E ret = node->element;
	delete node;
	--this->count;
	return ret;

}




template<typename E>
void DoubleCircleList<E>::printDoubleCircleList() {

	Node<E>* current = first;
	for (int i = 0; i < this->count; ++i) {
		if (i != 0)
			std::cout << " --> ";
		std::cout << current->prev->element << "_" << current->element << "_" << current->next->element;
		current = current->next;
	}
	std::cout << std::endl;

}




#endif // !_DOUBLECIRCLELIST_H_
