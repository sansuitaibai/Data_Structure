//利用双指针方法实现循环单向队列
#include<iostream>
#include<string>
#include"_dynamicSingleCircleQueue2.h"
using namespace std;

int main(){

    
    DSCQueue<int> d1;
    for(int i = 0; i < 10 ; ++i){
        d1.push(i);
    }
    d1.print(); //0 1 2 3 4 5 6 7 8 9 
    for(int i = 0; i < 10 ; ++i){
        d1.push(i);
    }
    d1.print();  // 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 
    cout << d1.pop() << endl;
    cout << d1.top()<<endl;
    d1.print();
    system("pause");
    return 0;
}