#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include<iostream>
#include<stack>
#include<queue>
template<typename E>
class BinTree;

template<typename E>
class BinTreeNode{
    friend class BinTree<E>; // һ��һ����Ԫ��ϵ
private:
    E data; // ������
    BinTreeNode* leftChild; //ָ�����֧ ������Ϊnull
    BinTreeNode* rightChild;// ָ���ҷ�֧������Ϊnull
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
    BinTreeNode<E>* root; // ���ڵ�
    E tag ; // ��һ������ı�ʶȷ�� �ýڵ�Ϊnull ����Ҫnew һ���������
public:
    BinTree():root(nullptr),tag(E()){

    }
    BinTree(E t):root(nullptr), tag(t){

    }
    ~BinTree(){
        
    }
public: // ����Ϊ���������ĸ�����
    void createBinTreeForKey();// ͨ���������� ����
    void createBinTreeForStr(const char* str);//ͨ��Ԥ�����úõ��ַ������д���
    void createBinTreeFor_pre_in(const char* pre , const char* in , int n );//ͨ���������������н��д���
    void createBinTreeFor_in_post(const char* in , const char* post, int n);//ͨ������ͺ�������н��д���
protected://���ϵĺ���ͨ���������µĺ������й����������� ��װ��
    void _createBinTreeFor_pre_in(BinTreeNode<E>*& t,const char* pre , const char* in , int n );//ͨ���������������н��д���
    void _createBinTreeFor_in_post(BinTreeNode<E>*& t,const char* in , const char* post, int n);//ͨ������ͺ�������н��д���
    void _createBinTree(BinTreeNode<E>*& t);//ͨ��ֱ������root ���д���
    void _createBinTree( const char * &str,BinTreeNode<E>*& t);//ͨ��ֱ������root , ����str���д���c
    BinTreeNode<E>* _createBinTree(const char* str);//ͨ���������������str���д��������ҷ���rootָ��
    BinTreeNode<E>* _createBinTree();// ͨ����������ķ�ʽ�����д������������ַ�ͨ����������
public: 
    void preOrder()const{ //�ݹ�ǰ�����
        std::cout <<"�ݹ�ǰ�������"<<std::endl;
        this->preOrder(root);
        std::cout << std::endl;
    }
    void inOrder()const{//�ݹ��������
        std::cout <<"�ݹ����������"<<std::endl;
        this->inOrder(root);
        std::cout << std::endl;
    }
    void postOrder()const{//�ݹ�������
        std::cout <<"�ݹ���������"<<std::endl;
        this->postOrder(root);
        std::cout << std::endl;
    }

protected:
    void preOrder(BinTreeNode<E>* t) const;
    void inOrder(BinTreeNode<E>* t)const;
    void postOrder(BinTreeNode<E>* t)const;

public: //���ַǵݹ�����������ķ�ʽ
    void preOrderStack();
    void inOrderStack();
    void postOrderStack();
    void levelOrderQueue();

};


// ����Ϊ���������ĸ�����
template<typename E>
void BinTree<E>::createBinTreeForKey()// ͨ���������� ����
{
    root = this->_createBinTree();
}




template<typename E>
void BinTree<E>::createBinTreeForStr(const char* str)//ͨ��Ԥ�����úõ��ַ������д���
{
    root = this->_createBinTreeForStr(str);
}





template<typename E>
void BinTree<E>::createBinTreeFor_pre_in(const char* pre , const char* in , int n )//ͨ���������������н��д���
{
   this->_createBinTreeFor_pre_in(root, pre, in, n);
}




template<typename E>
void BinTree<E>::createBinTreeFor_in_post(const char* in , const char* post, int n)//ͨ������ͺ�������н��д���
{
    this->_createBinTreeFor_in_post(root, in, post , n);
}





//���ϵĺ���ͨ���������µĺ������й����������� ��װ��

template<typename E>
void BinTree<E>::_createBinTreeFor_pre_in(BinTreeNode<E>*& t,const char* pre , const char* in , int n )//ͨ���������������н��д���
{
    if(n == 0){
        t = nullptr;
        return ;
    }
    int k = 0;
    while(pre[0] != in[k] ){
        ++k;
    }
    t = new BinTreeNode<E>(in[k]); //�������ڵ�
    this->_createBinTreeFor_pre_in(t->leftChild , pre + 1, in , k); //�����������Ľڵ�����͸�����������������
    this->_createBinTreeFor_pre_in(t->rightChild, pre + k + 1, in + k + 1, n - k - 1 ); // //�����������Ľڵ�����͸�����������������
    
}




template<typename E>
void BinTree<E>::_createBinTreeFor_in_post(BinTreeNode<E>*& t,const char* in , const char* post, int n)//ͨ������ͺ�������н��д���
{
    if(n == 0){
        t = nullptr;
        return ;
    }
    int k = 0;
    while(in[k] != post[n-1]){
        ++k;
    }
    t = new BinTreeNode<E>(in[k]); //�������ڵ�
    this->_createBinTreeFor_in_post(t->leftChild , in , post , k); // ����������
    this->_createBinTreeFor_in_post(t->rightChild , in + k + 1, post + k , n - k - 1); // ����������
    
}


template<typename E>
void BinTree<E>::_createBinTree( const char * &str,BinTreeNode<E>*& t)//ͨ��ֱ������root ���д���
{
    if(*str == this->tag){
        t = nullptr;
    }
    t  = new BinTreeNode<E>(*str);
    this->_createBinTree(++str, t->leftchild);
    this->_createBinTree(++str, t->rightChild);
}



template<typename E>
void BinTree<E>::_createBinTree(BinTreeNode<E>*& t)//ͨ��ֱ������root ���д���
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
BinTreeNode<E>* BinTree<E>::_createBinTree(const char* str)//ͨ���������������str���д��������ҷ���rootָ��
{
   

    BinTreeNode<E>* ret  = nullptr;
    if(*str != tag){
        ret = new BinTreeNode<E>(*str);
        ret->leftChild = this->_createBinTree(++str);
        ret->rightChild = this->_createBinTree(++str);
    }

}



template<typename E>
BinTreeNode<E>* BinTree<E>::_createBinTree()// ͨ����������ķ�ʽ�����д������������ַ�ͨ����������
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


//�����ķ�ʽ
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


//���ַǵݹ�����������ķ�ʽ
template<typename E>
void BinTree<E>::preOrderStack(){
    std::stack<BinTreeNode<E> *> s;
    if(root == nullptr) 
        return ;
    std::cout <<"�ǵݹ��������������"<<std::endl;
    s.push(root);
    BinTreeNode<E>* temp = nullptr;
    while(!s.empty()){
        temp = s.top();
        s.pop();//����ֵΪvoid
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
    std::cout <<"�ǵݹ��������������"<<std::endl;
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
    char tag; //L R  // L ��ʾ��ߵ������Ѿ����ʹ��ˣ��������ڷ���  R����ʾ��������ʼ���ʣ������Ѿ����ʹ���
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
    std::cout <<"�ǵݹ�������������"<<std::endl;
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
    std::cout <<"�ǵݹ�������������"<<std::endl; 
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


#endif //�� _BINARYTREE_H_