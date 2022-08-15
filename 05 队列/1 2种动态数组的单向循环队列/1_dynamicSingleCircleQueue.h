#ifndef _DYNAMICSINGLECIRCLEQUEUE_H_
#define _DYNAMICSINGLECIRCLEQUEUE_H_
#include<iostream>
#include<stdexcept>
#include<stdlib.h>

template<typename E>
class DSCQueue{
public:
    E * elements;
    int first; //首元素的位置
    int count; //元素的个数
    int capacity; //数组的容量
private:
    static const int DEFAULT_CAPACITY;
    int index(const int i);
    void ensureCapacity();
    
public:
    DSCQueue(const DSCQueue& r);
    DSCQueue();
    ~DSCQueue();
    int size();
    bool isEmpty();
    void  clear();
    void push(const E&);
    E pop();
    E top();
    void printDSCQueur(){
        if(this->count <= 0 ){
            return ;
        }
        std::cout << "size == "<< this->size() <<"   capacity: " << this->capacity <<  std::endl;
        for(int i = 0 ; i < this->count ; ++i){
            if(i != 0)
                std::cout << " -> ";
            std::cout << this->elements[this->index(i)];
        }
        std::cout << std::endl;
    }

};

template<typename E>
const int DSCQueue<E>::DEFAULT_CAPACITY = 10;

template<typename E>
int DSCQueue<E>::index(const int i){

    return (i + this->first) % this->capacity;

}

template<typename E>
void DSCQueue<E>::ensureCapacity(){
    int cap = this->count + 1;
    if(cap <= this->capacity)
        return ;
    int newcap = this->capacity + (this->capacity >> 1);
    E* newelements = new E[newcap];
    if(newelements == nullptr){
        abort();
    }
    for(int i = 0; i < this->capacity;++i){
        newelements[i] = this->elements[this->index(i)];
    }
    this->first = 0;
    this->capacity = newcap;
    this->elements = newelements;
    

}




  
template<typename E>
DSCQueue<E>::DSCQueue(const DSCQueue& r){

    E* newelements = new E[r.capacity];
    if(newelements == nullptr)
        abort();
    for(int i = 0 ; i < r.count ; ++i){
        newelements[i] = r.elements[ r.index[i]];
    }
    this->first = r.first;
    this->count = r.count;
    this->capacity = r.capacity;
    this->elements = newelements;

}


template<typename E>
DSCQueue<E>::DSCQueue(){
    this->elements = new E[this->DEFAULT_CAPACITY];
        if(this->elements == nullptr)
            abort();
    this->count = 0;
    this->capacity = this->DEFAULT_CAPACITY;
    this->first = 0;

}

template<typename E>
DSCQueue<E>::~DSCQueue(){

    this->clear();

}

template<typename E>
int DSCQueue<E>::size(){

    return this->count;
}

template<typename E>
bool DSCQueue<E>::isEmpty(){

    return this->count == 0;
    
}

template<typename E>
void DSCQueue<E>::clear(){
    if(this->capacity <=0 )
        return ;
    delete this->elements;
    this->elements = nullptr;
    this->first = 0;
    this->count = 0;
    this->capacity = 0;

}

template<typename E>
void DSCQueue<E>::push(const E& element){
    this->ensureCapacity();
    this->elements[this->index(this->count)] = element;
    ++this->count;
}

template<typename E>
E DSCQueue<E>::pop(){

    if(this->count <= 0)
        abort();
    E ret = this->elements[this->first];
    this->first = this->index(1);
    --this->count;
    return ret;

}

template<typename E>
E DSCQueue<E>::top(){
    if(this->count <= 0)
        abort();
    return this->elements[this->first];
}



#endif // !_DYNAMICSINGLECIRCLEQUEUE_H_
