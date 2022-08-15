#include<iostream>
#include<string>
#include"BinaryTree.h"
using namespace std;


int main(){
    BinTree<char> t1('#');
    t1.createBinTreeFor_pre_in("ABDEC","DBEAC",5);
    t1.preOrder();
    t1.inOrder();
    t1.postOrder();
    t1.preOrderStack();
    t1.inOrderStack();
    t1.postOrderStack();
    t1.levelOrderQueue();
    system("pause");
    return 0;
}