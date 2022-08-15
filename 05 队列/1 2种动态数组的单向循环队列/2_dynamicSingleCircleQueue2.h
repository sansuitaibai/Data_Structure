#ifndef _DYNAMICSINGLECIRCLEQUEUE_H_
#define _DYNAMICSINGLECIRCLEQUEUE_H_
#include<iostream>
#include<stdexcept>

#define IN 1    // 1 表示这是最后一个入队操作
#define OUT 0   //0 表示最后一个操作是出队操作

template<typename E>
class DSCQueue{

private:  
    int first; //头元素的位置
    int last ; //最后一个元素的下一个位置坐标
    int tag ;
    int capacity;
    E* elements;
    static const int DEFAULT_CAPACITY = 10;
public:
    DSCQueue(){
        this->first = 0;
        this->last = 0;
        this->tag = OUT;
        this->elements = new E[this->DEFAULT_CAPACITY];
        if(this->elements == nullptr)
            abort();
        this->capacity = this->DEFAULT_CAPACITY;
            
    }
    ~DSCQueue(){
        this->clear();
    }

    bool isFull(){
        return tag == IN && this->first == this->last;
    }
    bool isEmpty(){
        return tag == OUT && this->first == this->last;
    }
    int size(){
        if(this->isFull())
            return this->capacity;
        if(this->last >= this->first )
            return this->last - this->first;
        else{
            return this->capacity - (this->first - this->last);
        }
    }
    
    void clear(){
        this->first = 0;
         this->last = 0;
         this->tag = 0;
         this->capacity = 0;
        if(this->elements == nullptr)
         return ;
         delete this->elements;
         this->elements = nullptr;
         
    }
    
    void push(const E& element){
        if(this->isFull()){
            int cap = this->capacity + (this->capacity >> 1);
            E* newelements = new E[cap];
            for(int i = 0 ; i < this->capacity ; ++i){
                int index = (this->first + i + this->capacity ) % this->capacity; //被模数的this->capacity 可加可不加 
                newelements[i] = this->elements[index];
            }
            this->first = 0;
            this->last = this->capacity ; 
            this->tag = 0;
            this->capacity = cap;
            delete this->elements;
            this->elements = newelements;
        }
        this->elements[this->last] = element;
        this->last  = (this->last + 1 + this->capacity ) % this->capacity;
        this->tag = IN;
    }
    
    E pop(){
        if(this->isEmpty()){
            std::cout << "队列为空，并且返回对象的默认值"<<std::endl;
            return E();
        }
        E ret = this->elements[this->first];
        this->first = (this->first + 1 + this->capacity)%this->capacity;
        this->tag  = OUT;
        return ret;
    }
    
    E top(){
        if(this->size())
            return this->elements[this->first];
        else{
            std::cout << "队列为空，返回一个默认值"<<std::endl;
            return  E();
        }
    }

    void print(){
        if(this->isEmpty())
            return;
        int oldfirst = this->first;
        std::cout << "打印队列："<<std::endl;
        std::cout << "first: "<< this->first<<std::endl; 
        std::cout << "last: "<< this->last<<std::endl; 
        std::cout << "count: "<< this->size()<<std::endl; 
        std::cout << "capacity: "<< this->capacity<<std::endl;
        int size = this->size();
        while(size -- ){
            std::cout << this->elements[this->first] <<"  ";
            this->first =(this->first + 1 + this->capacity )%this->capacity;
            
        }
        std::cout <<std::endl;
        this->first = oldfirst;
    }
    



};









#endif //! _DYNAMICSINGLECIRCLEQUEUE_H_
