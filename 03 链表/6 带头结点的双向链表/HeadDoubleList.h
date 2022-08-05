#ifndef  _HEADDOUBLELIST_H_
#define	_HEADDOUBLELIST_H_
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
	Node(Node<E>* p, E element, Node<E>* n) {
		this->element = element;
		prev = p;
		next = n;
	}
	Node() {
		this->element = E();
		this->prev = nullptr;
		this->next = nullptr;
	}
};

template<typename E>
class HeadDoubleList {
private:
	Node<E>* first;
	Node<E>* last;
	int count;
public:
	static const int ELEMENT_NOT_FOUND;
private:
	void outOfRang(const std::string& s);
	void rangCheck(const int& index);
	void rangCheckForAdd(const int& index);

public:
	HeadDoubleList(int c, Node<E>* f, Node<E>* l);
	HeadDoubleList();
	~HeadDoubleList();

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

	void printHeadDoubleList();

};


template<typename E>
const int HeadDoubleList<E>::ELEMENT_NOT_FOUND = -1;


template<typename E>
HeadDoubleList<E>::HeadDoubleList(int c, Node<E>* f, Node<E>* l) {
	if (c <= 0)
		abort();
	this->count = c;
	this->first = f;
	this->last = l;
}


template<typename E>
HeadDoubleList<E>::HeadDoubleList() {

	this->first = nullptr;
	this->first = new Node<E>(nullptr, E(), nullptr);
	if (this->first == nullptr)
		abort();
	this->last = first;

	this->count = 0;
	
}


template<typename E>
HeadDoubleList<E>::~HeadDoubleList() {
	this->clear();
}






template<typename E>
void HeadDoubleList<E>::outOfRang(const std::string& s) {

	throw std::out_of_range(s);

}

template<typename E>
void HeadDoubleList<E>::rangCheck(const int& index) {

	if (index < 0 || index >= this->count)
		this->outOfRang("rangCheck index < 0 || index >= this->count");
}

template<typename E>
void HeadDoubleList<E>::rangCheckForAdd(const int& index) {

	if (index < 0 || index > this->count)
		this->outOfRang("rangCheckForAdd index < 0 || index > this->count");

}


template<typename E>
int HeadDoubleList<E>::size() {

	return this->count;

}

template<typename E>
bool HeadDoubleList<E>::isEmpty() {

	return this->count == 0;

}

template<typename E>
void HeadDoubleList<E>::clear() {

	Node<E>* current = first->next;
	Node<E>* temp = nullptr;
	while (current != nullptr) {
		temp = current->next;
		delete current;
		current = temp;
	}
	delete this->first;
	this->count = 0;
	this->first = nullptr;
	this->last = nullptr;
}

template<typename E>
bool HeadDoubleList<E>::contains(const E& element) {

	return this->indexOf(element) != this->ELEMENT_NOT_FOUND;
}

template<typename E>
int HeadDoubleList<E>::indexOf(const E& element) {

	Node<E>* current = first->next;
	for (int i = 0; i < this->count; ++i) {
		if (current->element == element) return i;
		current = current->next;
	}
	return this->ELEMENT_NOT_FOUND;

}


template<typename E>
E HeadDoubleList<E>::front() {

	return this->get(0);

}

template<typename E>
E HeadDoubleList<E>::back() {

	return this->get(this->count - 1);

}

template<typename E>
E HeadDoubleList<E>::get(const int& index) {
	this->rangCheck(index);
	return this->node(index)->element;

}

template<typename E>
E HeadDoubleList<E>::set(const int& index, const E& element) {
	Node<E>* node = this->node(index);
	E ret = node->element;
	node->element = element;
	return ret;

}



template<typename E>
void HeadDoubleList<E>::push_front(const E& element) {

	this->insert(0, element);

}

template<typename E>
void HeadDoubleList<E>::push_back(const E& element) {

	this->insert(this->count, element);
}

template<typename E>
Node<E>* HeadDoubleList<E>::node(const int& index) {
	this->rangCheck(index);
	Node<E>* current = first->next;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}
	return current;

}


template<typename E>
void HeadDoubleList<E>::insert(const int& index, const E& element) {
	this->rangCheckForAdd(index);
	if (index == this->count) {
		Node<E>* oldlast = last;
		last = new Node<E>(oldlast, element, nullptr);
		oldlast->next = last;
	}
	else {
		Node<E>* next = this->node(index);
		Node<E>* prev = next->prev;
		Node<E>* newnode = new Node<E>(prev, element, next);
		next->prev = newnode;
		prev->next = newnode;
	}

	++this->count;
}


template<typename E>
E HeadDoubleList<E>::pop_front() {

	return this->remove(0);

}

template<typename E>
E HeadDoubleList<E>::pop_back() {

	return this->remove(this->count - 1);
}

template<typename E>
E HeadDoubleList<E>::remove(const int& index) {
	this->rangCheck(index);
	Node<E>* node = this->node(index);
	Node<E>* prev = node->prev;
	Node<E>* next = node->next;
	E ret = node->element;



	
	prev->next = next;
	

	if (next == nullptr) {
		last = prev;
	}
	else {
		next->prev = prev;
	}



	--this->count;
	delete node;
	return ret;

}


template<typename E>
void HeadDoubleList<E>::printHeadDoubleList() {

	int n = this->count - 1;
	Node<E>* current = first->next;
	while (n--) {
		std::cout << current->element << " --> ";
		current = current->next;
	}
	std::cout << current->element << std::endl;

}









#endif // !_HEADDOUBLELIST_H_

