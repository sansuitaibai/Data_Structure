#include<iostream>
#include<string>
#include"1_dynamicSingleCircleQueue.h"
using namespace std;

int main(){



    std::cout << "-----------dynamicSingleCircleQueue ���Կ�ʼ-------------"<<std::endl;
    DSCQueue<int> q1;
    for(int i = 0; i < 10 ; ++i){
        q1.push(i);
    }
    q1.push(10);
    q1.printDSCQueur();
    std::cout << "ɾ��3��Ԫ��"<<std::endl;
    for(int i = 0 ;i  < 2 ; ++i){
        std::cout << q1.pop() << std::endl;
    }
    q1.printDSCQueur();
    for(int i = 0; i < 6 ; ++i){
        q1.push(i*10 + 33);
    }
    q1.printDSCQueur();
    system("pause");
    return 0;
}