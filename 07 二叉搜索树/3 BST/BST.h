#ifndef _BST_H_
#define _BST_H_     //二叉搜索树
#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<new>

template<typename E> 
struct Node{
public:
    E element;
    Node<E>* lchild;
    Node<E>* rchild;
    Node<E>* parent;
    Node(const E & e , Node<E>* p):element(e), parent(p) , lchild(nullptr), rchild(nullptr){

    }
    ~Node(){
        
    }
    bool isLeaf(){ // 判断该节点是否为叶子节点
        return lchild == nullptr && rchild == nullptr;
    }
    bool hasTwoChild(){// 判断该节点是否有两个孩子

        return lchild != nullptr && rchild != nullptr;
    }


};

template<typename E>
class BST{
private: 
    Node<E>* root;
    int count ;
    
public:
    BST(){
        root = nullptr;
        count = 0;
    }
    ~BST(){
        this->clear();
    }

public:
    int size(); //二叉树有多少个节点
    bool isEmpty(); // 二叉搜索树是否为空
    void clear();//将二叉搜索树清空
    bool contains(const E& e); // 判断该元素值是否在二叉搜索树中
    void add(const E& e); // 生成该二叉搜索树的节点 ， 添加到树中
    void remove(const E& e);//删除对应值的节点
private: 
    
    int compare(const E& e1 , const E& e2 );// 比较该值和树中节点的值
    Node<E>* node(const E& e);//获取该值对应的节点， 没有返回nullptr

    
    Node<E>* predecessor(Node<E>* node);//获取该节点的前驱节点
    Node<E>* successor(Node<E>* node);//获取该节点的后继节点

    void remove(Node<E>* node);//将该节点删除

public:
    void preorder();//前序遍历
    void inorder();//中序遍历
    void postorder();//后序遍历
    void levelorder();//层次遍历


private:

    void preorder(Node<E>* node);//前序遍历
    void inorder(Node<E>* node);//中序遍历
    void postorder(Node<E>* node);//后序遍历
    void levelorder(Node<E>* node);//层次遍历
    
public:
    int height();//迭代求二叉搜索树的高度
    int height2();//递归求二叉树的高度
    int height(Node<E>* node);//递归求二叉树的高度
    bool isComplete();//迭代判断二叉树是否为完全二叉树
    

public:
   void printBst();//打印二叉搜索树

private:
    void printBst(Node<E>* node, std::string prefix);// 打印二叉树

};
 


template<typename E>
int BST<E>::size()//二叉树有多少个节点
{
        return this->count;
}


template<typename E>
bool BST<E>::isEmpty() // 二叉搜索树是否为空
{

    return this->count == 0;

}


template<typename E>
void BST<E>::clear()//将二叉搜索树清空
{
    if(this->root == nullptr) return ;
    std::stack<Node<E>* > s ;
    s.push(root);
    Node<E>* tmp ;
    while(!s.empty()){
        tmp = s.top();
        s.pop();
        if(tmp->lchild != nullptr){
            s.push(tmp->lchild);
        }
        if(tmp->rchild != nullptr){
            s.push(tmp->rchild);
        }
        delete tmp;

    }
    this->count  = 0;
    this->root = nullptr;


}

template<typename E>
bool BST<E>::contains(const E& e)// 判断该元素值是否在二叉搜索树中
{

    return this->node(e) != nullptr;

}


template<typename E>
void BST<E>::add(const E& e) // 生成该二叉搜索树的节点 ， 添加到树中
{
    

    if(this->root == nullptr){
        root = new Node<E>(e, nullptr);
        ++this->count;
        return ;
    }
    Node<E>* tmp = root; // 利用tmp 找到对应的插入节点的位置 
    Node<E>* parent = nullptr; // 插入节点的父节点
    int cmp = 0;
    while(tmp != nullptr){
        cmp = this->compare(e , tmp->element);
        parent = tmp;
        if(cmp > 0){
            tmp =  tmp->rchild;
        }else if(cmp < 0) 
        { 
            tmp = tmp->lchild;
        }else{ // 二叉树里面有对应的值节点， 进行覆盖节点的data域
            tmp->element = e;
            return ;
        }
    }
    Node<E>* newnode = new Node<E>(e,parent );
    if(cmp < 0){
        parent->lchild = newnode;
    }else{
        parent->rchild = newnode;
    }
    ++this->count;

}

template<typename E>
void BST<E>::remove(const E& e)//删除对应值的节点
{

    this->remove(node(e));

}

template<typename E>
int BST<E>::compare(const E& e1, const E& e2)// 比较该值和树中节点的值
{
    return e1 - e2;
}


template<typename E>
Node<E>* BST<E>::node(const E& e)//获取该值对应的节点， 没有返回nullptr
{
    Node<E>* tmp = this->root;
    int cmp = 0;
    while(tmp != nullptr){
        cmp = this->compare(e ,tmp->element);
        if(cmp > 0){
            tmp = tmp->rchild;
        }else if(cmp < 0){
            tmp = tmp->lchild;
        }else{
            return tmp;
        }
    }
    return nullptr;


}




template<typename E>
Node<E>* BST<E>::predecessor(Node<E>* node)//获取该节点的前驱节点 ,没有返回nullptr
{

    Node<E>* tmp = node->lchild;
    if(tmp != nullptr){
        while(tmp->rchild != nullptr)
            tmp = tmp->rchild;
        return tmp;
    }
    

    while(tmp->parent != nullptr && tmp == tmp->parent->lchild){ //根节点的前驱节点为空
        tmp = tmp->parent;
    }
    return tmp->parent;
    



}

template<typename E>
Node<E>* BST<E>::successor(Node<E>* node)//获取该节点的后继节点
{

    Node<E>* tmp  = node->rchild;
    if(tmp != nullptr){
        while(tmp->lchild != nullptr){
            tmp = tmp->lchild;
        }
        return tmp;
    }
    while(tmp->parent != nullptr && tmp == tmp->parent->rchild){
        tmp  = tmp->parent;
    }
    return tmp->parent;


}

template<typename E>
void BST<E>::remove(Node<E>* node)//将该节点删除
{
    if(node == nullptr)
        return ;
    
    if(node->hasTwoChild()){
        Node<E>* succ = this->successor(node);
        node->element = succ->element;
        node = succ;
    }
    Node<E>* next = node->lchild != nullptr ? node->lchild : node->rchild;
    if(next != nullptr){//删除度为1 的节点
        next->parent = node->parent;
        if(node->parent == nullptr){ // 删除度为1 的节点 并且是根节点
            this->root = next;
        }else if(node->parent->lchild == node){
            node->parent->lchild = next;
        }else{

            node->parent->rchild = next;
        }
    }else{ //删除的是叶子节点
        if(node->parent == nullptr){ //度为0 且为根节点
            root = nullptr;
        }else if(node == node->parent->lchild){  
            node->parent->lchild = nullptr;
        }else{
            node->parent->rchild = nullptr;
        }
    }
    delete node;
    --this->count;


}

template<typename E>
void BST<E>::preorder()//前序遍历
{

    std::cout << "递归的前序遍历：" <<std::endl;
    this->preorder(root);
    std::cout << std::endl;

}


template<typename E>
void BST<E>::inorder()//中序遍历
{
    std::cout << "递归的中序遍历：" <<std::endl;
    this->inorder(root);
    std::cout << std::endl;


}


template<typename E>
void BST<E>::postorder()//后序遍历
{

    std::cout << "递归的后序遍历：" <<std::endl;
    this->postorder(root);
    std::cout << std::endl;

}


template<typename E>
void BST<E>::levelorder()//层次遍历
{

    std::cout << "层次遍历：" <<std::endl;
    this->levelorder(root);
    std::cout << std::endl;

}

template<typename E>
void BST<E>::preorder( Node<E>* node)//前序遍历
{

    if(node == nullptr){
        return;
    }
    std::cout << node->element << "  " ;
    this->preorder(node->lchild);
    this->preorder(node->rchild);


}


template<typename E>
void BST<E>::inorder(Node<E>* node)//中序遍历
{
    if(node == nullptr)
        return ;
    this->inorder(node->lchild);
    std::cout << node->element <<"  ";
    this->inorder(node->rchild);


}

template<typename E>
void BST<E>::postorder(Node<E>* node)//后序遍历
{
    if(node == nullptr)
        return ;
    this->postorder(node->lchild);
    this->postorder(node->rchild);
    std::cout << node->element << "  ";


}

template<typename E>
void BST<E>::levelorder(Node<E>* node)//层次遍历
{
    if(node == nullptr)
        return ;
    Node<E>* tmp = nullptr;
    std::queue<Node<E>*> s;
    s.push(root);
    while(!s.empty()){
        tmp = s.front();
        s.pop();
        if(tmp->lchild != nullptr){
            s.push(tmp->lchild);
        }
        if(tmp->rchild != nullptr){
            s.push(tmp->rchild);
        }
        std::cout << tmp->element << "  ";
    }


}

template<typename E>
int BST<E>::height()//迭代求二叉搜索树的高度
{

    if(root == nullptr)
        return 0;
   int h = 0;
   Node<E>* tmp = nullptr;
   int levelsize = 1;
    std::queue<Node<E>*> s;
    s.push(root);
    while(!s.empty()){
        tmp = s.front();
        s.pop();
        --levelsize;
        if(tmp->lchild != nullptr){
            s.push(tmp->lchild);
        }
        if(tmp->rchild != nullptr){
            s.push(tmp->rchild);
        }
        if(levelsize == 0){
            levelsize = s.size();
            ++h;
        }
    }

    return h;

}

template<typename E>
int BST<E>::height2()//递归求二叉树的高度
{

    return this->height(root);


}

template<typename E>
int BST<E>::height(Node<E>* node)//递归求二叉树的高度
{

   if(node == nullptr)
        return 0;
    return std::max(this->height(node->lchild) , this->height(node->rchild)) + 1;


}

template<typename E>
bool BST<E>::isComplete()//迭代判断二叉树是否为完全二叉树
{
    if(root == nullptr)
        return true;
    Node<E>* tmp = nullptr;
    std::queue<Node<E>*> s;
    s.push(root);
    bool isrun = false;
    while(!s.empty()){
        tmp = s.front();
        s.pop();
        if(isrun && !tmp->isLeaf()){
            return false;
        }
        if(tmp->lchild != nullptr){
            s.push(tmp->lchild);
        }else if(tmp->rchild != nullptr){
            return false;
        }
        if(tmp->rchild != nullptr){
            s.push(tmp->rchild);
        }else{
            isrun = true;
        }
       
    }

    return true;
}




template<typename E>
void BST<E>::printBst()//打印二叉搜索树
{
    if(this->root == nullptr)
        return ;
    printBst(root,"");
    

}
template<typename E>
void BST<E>::printBst( Node<E>* node, std::string prefix)// 打印二叉树
{
    if(node == nullptr) return ;
   
    std::cout << prefix << node->element  << std::endl;
    this->printBst(node->lchild , prefix + "L");
    this->printBst(node->rchild , prefix + "R");

}

#endif // ! _BST_H_