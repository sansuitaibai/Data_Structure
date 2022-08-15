#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include<iostream>
#include<stack>
#include<queue>
template<typename E>
class BinTree;

template<typename E>
class BinTreeNode{
    friend class BinTree<E>; // 一对一的友元关系
private:
    E data; // 数据域
    BinTreeNode* leftChild; //指向左分支 ，或者为null
    BinTreeNode* rightChild;// 指向右分支，或者为null
public:
    BinTreeNode():data(E()),leftChild(nullptr),rightChild(nullptr){

    }
    BinTreeNode(E d, BinTreeNode* left = nullptr, BinTreeNode* right = nullptr):
        data(d), leftChild(left),rightChild(right){

    }
    ~BinTreeNode(){};
};


template<typename E> 
class BinTree{
private:
    BinTreeNode<E>* root; // 根节点
    E tag ; // 以一个特殊的标识确定 该节点为null 还是要new 一个对象出来
public:
    BinTree():root(nullptr),tag(E()){

    }
    BinTree(E t):root(nullptr), tag(t){

    }
    ~BinTree(){
        
    }
public: // 以下为创建树的四个函数
    void createBinTreeForKey();// 通过键盘输入 创建
    void createBinTreeForStr(const char* str);//通过预先设置好的字符串进行创建
    void createBinTreeFor_pre_in(const char* pre , const char* in , int n );//通过先序和中序的序列进行创建
    void createBinTreeFor_in_post(const char* in , const char* post, int n);//通过中序和后序的序列进行创建
protected://以上的函数通过调用以下的函数进行构建二叉树， 封装性
    void _createBinTreeFor_pre_in(BinTreeNode<E>*& t,const char* pre , const char* in , int n );//通过先序和中序的序列进行创建
    void _createBinTreeFor_in_post(BinTreeNode<E>*& t,const char* in , const char* post, int n);//通过中序和后序的序列进行创建
    void _createBinTree(BinTreeNode<E>*& t);//通过直接引用root 进行创建
    void _createBinTree( const char * &str,BinTreeNode<E>*& t);//通过直接引用root , 利用str进行创建c
    BinTreeNode<E>* _createBinTree(const char* str);//通过层序遍历的序列str进行创建，并且返回root指针
    BinTreeNode<E>* _createBinTree();// 通过先序遍历的方式，进行创建二叉树，字符通过键盘输入
public: 
    void preOrder()const{ //递归前序遍历
        std::cout <<"递归前序遍历："<<std::endl;
        this->preOrder(root);
        std::cout << std::endl;
    }
    void inOrder()const{//递归中序遍历
        std::cout <<"递归中序遍历："<<std::endl;
        this->inOrder(root);
        std::cout << std::endl;
    }
    void postOrder()const{//递归后序遍历
        std::cout <<"递归后序遍历："<<std::endl;
        this->postOrder(root);
        std::cout << std::endl;
    }

protected:
    void preOrder(BinTreeNode<E>* t) const;
    void inOrder(BinTreeNode<E>* t)const;
    void postOrder(BinTreeNode<E>* t)const;

public: //四种非递归遍历二叉树的方式
    void preOrderStack();
    void inOrderStack();
    void postOrderStack();
    void levelOrderQueue();

};


// 以下为创建树的四个函数
template<typename E>
void BinTree<E>::createBinTreeForKey()// 通过键盘输入 创建
{
    root = this->_createBinTree();
}




template<typename E>
void BinTree<E>::createBinTreeForStr(const char* str)//通过预先设置好的字符串进行创建
{
    root = this->_createBinTreeForStr(str);
}





template<typename E>
void BinTree<E>::createBinTreeFor_pre_in(const char* pre , const char* in , int n )//通过先序和中序的序列进行创建
{
   this->_createBinTreeFor_pre_in(root, pre, in, n);
}




template<typename E>
void BinTree<E>::createBinTreeFor_in_post(const char* in , const char* post, int n)//通过中序和后序的序列进行创建
{
    this->_createBinTreeFor_in_post(root, in, post , n);
}





//以上的函数通过调用以下的函数进行构建二叉树， 封装性

template<typename E>
void BinTree<E>::_createBinTreeFor_pre_in(BinTreeNode<E>*& t,const char* pre , const char* in , int n )//通过先序和中序的序列进行创建
{
    if(n == 0){
        t = nullptr;
        return ;
    }
    int k = 0;
    while(pre[0] != in[k] ){
        ++k;
    }
    t = new BinTreeNode<E>(in[k]); //创建根节点
    this->_createBinTreeFor_pre_in(t->leftChild , pre + 1, in , k); //计算左子树的节点的起点和个数，将左子树传入
    this->_createBinTreeFor_pre_in(t->rightChild, pre + k + 1, in + k + 1, n - k - 1 ); // //计算右子树的节点的起点和个数，将右子树传入
    
}




template<typename E>
void BinTree<E>::_createBinTreeFor_in_post(BinTreeNode<E>*& t,const char* in , const char* post, int n)//通过中序和后序的序列进行创建
{
    if(n == 0){
        t = nullptr;
        return ;
    }
    int k = 0;
    while(in[k] != post[n-1]){
        ++k;
    }
    t = new BinTreeNode<E>(in[k]); //创建根节点
    this->_createBinTreeFor_in_post(t->leftChild , in , post , k); // 创建左子树
    this->_createBinTreeFor_in_post(t->rightChild , in + k + 1, post + k , n - k - 1); // 创建右子树
    
}


template<typename E>
void BinTree<E>::_createBinTree( const char * &str,BinTreeNode<E>*& t)//通过直接引用root 进行创建
{
    if(*str == this->tag){
        t = nullptr;
    }
    t  = new BinTreeNode<E>(*str);
    this->_createBinTree(++str, t->leftchild);
    this->_createBinTree(++str, t->rightChild);
}



template<typename E>
void BinTree<E>::_createBinTree(BinTreeNode<E>*& t)//通过直接引用root 进行创建
{
    E data; 
    std::cin >> data;
    if(data == this->tag){
        t == nullptr;
    }
    t = new BinTreeNode<E>(data);
    this->_createBinTree(t->leftchild);
    this->_createBinTree(t->rightchild);
}



template<typename E>
BinTreeNode<E>* BinTree<E>::_createBinTree(const char* str)//通过层序遍历的序列str进行创建，并且返回root指针
{
   

    BinTreeNode<E>* ret  = nullptr;
    if(*str != tag){
        ret = new BinTreeNode<E>(*str);
        ret->leftChild = this->_createBinTree(++str);
        ret->rightChild = this->_createBinTree(++str);
    }

}



template<typename E>
BinTreeNode<E>* BinTree<E>::_createBinTree()// 通过先序遍历的方式，进行创建二叉树，字符通过键盘输入
{
    BinTreeNode<E>* ret = nullptr;
    E data; 
    std::cin >> data;
    if(data =! this->tag){
        ret = new BinTreeNode<E>(data);
        ret->leftChild  = this->_createBinTree();
        ret->rightChild = this->_createBinTree();
    }
    return ret;
}


//遍历的方式
template<typename E>
void BinTree<E>::preOrder(BinTreeNode<E>* t) const
{
    if(t == nullptr){
        return;
    }
    std::cout << t->data << "  ";
    this->preOrder(t->leftChild);
    this->postOrder(t->rightChild);
    

}


template<typename E>
void BinTree<E>::inOrder(BinTreeNode<E>* t)const
{
    if(t == nullptr)
        return;
    this->inOrder(t->leftChild);
    std::cout << t->data << "  ";
    this->inOrder(t->rightChild);


}

template<typename E>
void BinTree<E>::postOrder(BinTreeNode<E>* t)const
{
    if(t == nullptr)
        return;
    this->postOrder(t->leftChild);
    this->postOrder(t->rightChild);
    std::cout << t->data << "  ";


}


//四种非递归遍历二叉树的方式
template<typename E>
void BinTree<E>::preOrderStack(){
    std::stack<BinTreeNode<E> *> s;
    if(root == nullptr) 
        return ;
    std::cout <<"非递归先序遍历二叉树"<<std::endl;
    s.push(root);
    BinTreeNode<E>* temp = nullptr;
    while(!s.empty()){
        temp = s.top();
        s.pop();//返回值为void
        std::cout << temp->data <<"  ";
        if(temp->rightChild != nullptr)
            s.push(temp->rightChild);
        if(temp->leftChild != nullptr) 
            s.push(temp->leftChild);
    }
    std::cout << std::endl;
}


template<typename E>
void BinTree<E>::inOrderStack()
{
    if(root == nullptr) 
        return;
    std::cout <<"非递归中序遍历二叉树"<<std::endl;
    std::stack<BinTreeNode<E>*> s;
    BinTreeNode<E>* temp = root;
    do
    {
        while(temp != nullptr){
            s.push(temp);
            temp = temp->leftChild;
        }
        if(!s.empty()){
            temp = s.top();
            s.pop();
            std::cout << temp->data <<"  ";
            temp = temp->rightChild;

        }
        
        
        
        
    } while (!s.empty() || temp != nullptr);
    
    std::cout << std::endl;
    
}

template<typename E>
struct Node
{
    BinTreeNode<E>* node;
    char tag; //L R  // L 表示左边的数据已经访问过了，或者正在访问  R　表示右子树开始访问，或者已经访问过了
    Node(BinTreeNode<E>*& n,char& c):node(n),tag(c){

    }
    Node():node(nullptr),tag('L'){

    }
    ~Node(){}
    /* data */
};


template<typename E>
void BinTree<E>::postOrderStack()
{

    if(root == nullptr)
        return ;
    std::cout <<"非递归后序遍历二叉树"<<std::endl;
    std::stack<Node<E> > s;
    BinTreeNode<E>* temp = root;
    Node<E> n;
    
    do
    {
        
        while(temp != nullptr){
            n.node = temp;
            n.tag = 'L';
            s.push(n);
            temp  = temp->leftChild;
        }
        bool flag = true;
        while(flag && !s.empty()){
            n = s.top();
            s.pop();
           if(n.tag == 'R'){
                std::cout << n.node->data << "  ";
           }else{
                n.tag = 'R';
                s.push(n);
                temp = n.node->rightChild;
                flag = false;
           } 
        }




    } while (! s.empty());
    
    std::cout << std::endl;

}

template<typename E>
void BinTree<E>::levelOrderQueue()
{
    if(root == nullptr)
        return;
    std::cout <<"非递归层序遍历二叉树"<<std::endl; 
    std::queue<BinTreeNode<E>* > q;
    q.push(root);
    BinTreeNode<E>* temp = nullptr;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        std::cout << temp->data << "  ";
        if(temp->leftChild != nullptr)
            q.push(temp->leftChild);
        if(temp->rightChild != nullptr)
            q.push(temp->rightChild);
    }

    std::cout << std::endl;
}


#endif //！ _BINARYTREE_H_