#ifndef _DYNAMICSINGLECIRCLEQUEUE_H_
#define _DYNAMICSINGLECIRCLEQUEUE_H_
#include<iostream>
#include<stdexcept>

#define IN 1    // 1 ��ʾ�������һ����Ӳ���
#define OUT 0   //0 ��ʾ���һ�������ǳ��Ӳ���

template<typename E>
class DSCQueue{

private:  
    int first; //ͷԪ�ص�λ��
    int last ; //���һ��Ԫ�ص���һ��λ������
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
                int index = (this->first + i + this->capacity ) % this->capacity; //��ģ����this->capacity �ɼӿɲ��� 
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
            std::cout << "����Ϊ�գ����ҷ��ض����Ĭ��ֵ"<<std::endl;
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
            std::cout << "����Ϊ�գ�����һ��Ĭ��ֵ"<<std::endl;
            return  E();
        }
    }

    void print(){
        if(this->isEmpty())
            return;
        int oldfirst = this->first;
        std::cout << "��ӡ���У�"<<std::endl;
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
