#include<iostream>
#include<string>
#include"dynamicDoubleCircleQueue.h"
using namespace std;


int main(){

  
    cout << "循环双端队列测试开始："<<endl;
    DDCQueue<int> d1;
    for(int i = 0; i < 10 ; ++i){
        d1.push_front(1 + i);
        d1.push_back(101 + i);
    }
    d1.printDDCQueue();
    cout << d1.pop_front() <<"  "<< d1.pop_back()<<endl;
    d1.printDDCQueue();
    system("pause");
    return 0;
}