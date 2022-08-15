#ifndef _DYNAMICDOUBLECIRCLEQUEUE_H_
#define _DYNAMICDOUBLECIRCLEQUEUE_H_  //鍔ㄦ�佹暟缁勫弻绔?寰?鐜?闃熷垪

#include<iostream>
#include<stdexcept>
using namespace std;
template<typename E>
class DDCQueue{

private:
    int first;
    int count;
    int capacity;
    E* elements;
    static const int DEFAULT_CAPACITY = 10;
public:
    DDCQueue(){
        this->capacity = this->DEFAULT_CAPACITY;
        this->first = 0;
        this->count = 0;
        this->elements = new E[this->capacity];
        if(this->elements == nullptr)
            abort();
        
    }

    ~DDCQueue(){
        this->clear();
    }
public:
    int size();
    bool isEmpty();
    void clear();
    int index(int i);
    void push_front(const E& element);
    void push_back(const E& element);
    E pop_front();
    E pop_back();
    E front();
    E back();
    void printDDCQueue();

private:
    void ensureCapacity();



};

template<typename E>
int DDCQueue<E>::size(){

    return this->count;

}


template<typename E>
bool DDCQueue<E>::isEmpty(){


    return this->count == 0;
}


template<typename E>
void DDCQueue<E>::clear(){

    if(this->elements == nullptr)
        return ;
    delete this->elements;
    this->count = 0;
    this->first = 0;
    this->capacity = 0;

}

template<typename E>
int DDCQueue<E>::index(int i){
    
    i += this->first;
    if(i < 0 )
        i += this->capacity;
    return i % this->capacity;

}


template<typename E>
void DDCQueue<E>::push_front(const E& element){
    this->ensureCapacity();
    this->first = this->index(-1);
    this->elements[this->first] = element;
    
    ++this->count;
}


template<typename E>
void DDCQueue<E>::push_back(const E& element){
    this->ensureCapacity();
    this->elements[this->index(this->count)] = element;
    ++this->count;

}


template<typename E>
E DDCQueue<E>::pop_front(){

    E ret = this->elements[this->first];
    this->first = this->index(1);
    --this->count;
    return ret;

}


template<typename E>
E DDCQueue<E>::pop_back(){

    E ret = this->elements[this->index(this->count - 1)];
    --this->count;
    return ret;

}


template<typename E>
E DDCQueue<E>::front(){


    return this->elements[this->first];

}


template<typename E>
E DDCQueue<E>::back(){

    return this->elements[this->index(this->count - 1)];
}

template<typename E>
void DDCQueue<E>::printDDCQueue(){

    
    cout << "循环双端队列打印： "<<endl;
    cout << "count: "<< this->count << endl;
    cout << "first: "<<this->first << endl;
    cout << "capacity: "<<this->capacity <<endl;
    for(int i = 0 ; i < this->count; ++i){
        if(i != 0)
            std::cout << " --> ";
        std::cout << this->elements[this->index(i)]; 
    }
    std::cout << std::endl;

}


template<typename E>
void DDCQueue<E>::ensureCapacity(){
    int cap = this->count + 1;
    if(cap <= this->capacity)
        return ;
    cap = this->capacity + (this->capacity >> 1);
    E* newelements = new E[cap];
    if(newelements == nullptr) 
        abort();
    for(int i = 0; i < this->count ; ++i){
        newelements[i] = this->elements[this->index(i)];
    }
    delete this->elements;
    this->capacity = cap;
    this->first = 0;
    this->elements = newelements;
    

}






#endif // ! _DYNAMICDOUBLECIRCLEQUEUE_H_