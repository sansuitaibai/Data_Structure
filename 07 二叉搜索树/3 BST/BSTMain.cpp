#include<iostream>
#include<string>
#include"BST.h"
using namespace std;


int main(){


    BST<int> b1;
    b1.add(7);
    b1.add(4);
    b1.add(9);
    b1.add(2);
    b1.add(8);
    b1.add(11);
    b1.printBst();
    b1.preorder();
    b1.inorder();
    b1.postorder();
    b1.levelorder();
    std::cout << b1.height2() << endl;
    std::cout << b1.height() <<endl;
    if(b1.isComplete()){
        std::cout << "this is complete tree" << endl;
    }else{
        std::cout << "this is not complete tree" << endl;
    }
    b1.add(5);
    b1.levelorder();
    if(b1.isComplete()){
        std::cout << "this is complete tree" << endl;
    }else{
        std::cout << "this is not complete tree" << endl;
    }

    b1.add(1);
    b1.levelorder();
    if(b1.isComplete()){
        std::cout << "this is complete tree" << endl;
    }else{
        std::cout << "this is not complete tree" << endl;
    }
    b1.add(3);
    b1.levelorder();
    if(b1.isComplete()){
        std::cout << "this is complete tree" << endl;
    }else{
        std::cout << "this is not complete tree" << endl;
    }
    b1.remove(1);
    b1.remove(3);
    b1.levelorder();
    b1.remove(4);
    b1.printBst();
    b1.remove(7);
    b1.printBst();
    system("pause");
    return 0;
}