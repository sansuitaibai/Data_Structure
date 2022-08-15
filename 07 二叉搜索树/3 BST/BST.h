#ifndef _BST_H_
#define _BST_H_     //����������
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
    bool isLeaf(){ // �жϸýڵ��Ƿ�ΪҶ�ӽڵ�
        return lchild == nullptr && rchild == nullptr;
    }
    bool hasTwoChild(){// �жϸýڵ��Ƿ�����������

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
    int size(); //�������ж��ٸ��ڵ�
    bool isEmpty(); // �����������Ƿ�Ϊ��
    void clear();//���������������
    bool contains(const E& e); // �жϸ�Ԫ��ֵ�Ƿ��ڶ�����������
    void add(const E& e); // ���ɸö����������Ľڵ� �� ��ӵ�����
    void remove(const E& e);//ɾ����Ӧֵ�Ľڵ�
private: 
    
    int compare(const E& e1 , const E& e2 );// �Ƚϸ�ֵ�����нڵ��ֵ
    Node<E>* node(const E& e);//��ȡ��ֵ��Ӧ�Ľڵ㣬 û�з���nullptr

    
    Node<E>* predecessor(Node<E>* node);//��ȡ�ýڵ��ǰ���ڵ�
    Node<E>* successor(Node<E>* node);//��ȡ�ýڵ�ĺ�̽ڵ�

    void remove(Node<E>* node);//���ýڵ�ɾ��

public:
    void preorder();//ǰ�����
    void inorder();//�������
    void postorder();//�������
    void levelorder();//��α���


private:

    void preorder(Node<E>* node);//ǰ�����
    void inorder(Node<E>* node);//�������
    void postorder(Node<E>* node);//�������
    void levelorder(Node<E>* node);//��α���
    
public:
    int height();//����������������ĸ߶�
    int height2();//�ݹ���������ĸ߶�
    int height(Node<E>* node);//�ݹ���������ĸ߶�
    bool isComplete();//�����ж϶������Ƿ�Ϊ��ȫ������
    

public:
   void printBst();//��ӡ����������

private:
    void printBst(Node<E>* node, std::string prefix);// ��ӡ������

};
 


template<typename E>
int BST<E>::size()//�������ж��ٸ��ڵ�
{
        return this->count;
}


template<typename E>
bool BST<E>::isEmpty() // �����������Ƿ�Ϊ��
{

    return this->count == 0;

}


template<typename E>
void BST<E>::clear()//���������������
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
bool BST<E>::contains(const E& e)// �жϸ�Ԫ��ֵ�Ƿ��ڶ�����������
{

    return this->node(e) != nullptr;

}


template<typename E>
void BST<E>::add(const E& e) // ���ɸö����������Ľڵ� �� ��ӵ�����
{
    

    if(this->root == nullptr){
        root = new Node<E>(e, nullptr);
        ++this->count;
        return ;
    }
    Node<E>* tmp = root; // ����tmp �ҵ���Ӧ�Ĳ���ڵ��λ�� 
    Node<E>* parent = nullptr; // ����ڵ�ĸ��ڵ�
    int cmp = 0;
    while(tmp != nullptr){
        cmp = this->compare(e , tmp->element);
        parent = tmp;
        if(cmp > 0){
            tmp =  tmp->rchild;
        }else if(cmp < 0) 
        { 
            tmp = tmp->lchild;
        }else{ // �����������ж�Ӧ��ֵ�ڵ㣬 ���и��ǽڵ��data��
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
void BST<E>::remove(const E& e)//ɾ����Ӧֵ�Ľڵ�
{

    this->remove(node(e));

}

template<typename E>
int BST<E>::compare(const E& e1, const E& e2)// �Ƚϸ�ֵ�����нڵ��ֵ
{
    return e1 - e2;
}


template<typename E>
Node<E>* BST<E>::node(const E& e)//��ȡ��ֵ��Ӧ�Ľڵ㣬 û�з���nullptr
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
Node<E>* BST<E>::predecessor(Node<E>* node)//��ȡ�ýڵ��ǰ���ڵ� ,û�з���nullptr
{

    Node<E>* tmp = node->lchild;
    if(tmp != nullptr){
        while(tmp->rchild != nullptr)
            tmp = tmp->rchild;
        return tmp;
    }
    

    while(tmp->parent != nullptr && tmp == tmp->parent->lchild){ //���ڵ��ǰ���ڵ�Ϊ��
        tmp = tmp->parent;
    }
    return tmp->parent;
    



}

template<typename E>
Node<E>* BST<E>::successor(Node<E>* node)//��ȡ�ýڵ�ĺ�̽ڵ�
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
void BST<E>::remove(Node<E>* node)//���ýڵ�ɾ��
{
    if(node == nullptr)
        return ;
    
    if(node->hasTwoChild()){
        Node<E>* succ = this->successor(node);
        node->element = succ->element;
        node = succ;
    }
    Node<E>* next = node->lchild != nullptr ? node->lchild : node->rchild;
    if(next != nullptr){//ɾ����Ϊ1 �Ľڵ�
        next->parent = node->parent;
        if(node->parent == nullptr){ // ɾ����Ϊ1 �Ľڵ� �����Ǹ��ڵ�
            this->root = next;
        }else if(node->parent->lchild == node){
            node->parent->lchild = next;
        }else{

            node->parent->rchild = next;
        }
    }else{ //ɾ������Ҷ�ӽڵ�
        if(node->parent == nullptr){ //��Ϊ0 ��Ϊ���ڵ�
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
void BST<E>::preorder()//ǰ�����
{

    std::cout << "�ݹ��ǰ�������" <<std::endl;
    this->preorder(root);
    std::cout << std::endl;

}


template<typename E>
void BST<E>::inorder()//�������
{
    std::cout << "�ݹ�����������" <<std::endl;
    this->inorder(root);
    std::cout << std::endl;


}


template<typename E>
void BST<E>::postorder()//�������
{

    std::cout << "�ݹ�ĺ��������" <<std::endl;
    this->postorder(root);
    std::cout << std::endl;

}


template<typename E>
void BST<E>::levelorder()//��α���
{

    std::cout << "��α�����" <<std::endl;
    this->levelorder(root);
    std::cout << std::endl;

}

template<typename E>
void BST<E>::preorder( Node<E>* node)//ǰ�����
{

    if(node == nullptr){
        return;
    }
    std::cout << node->element << "  " ;
    this->preorder(node->lchild);
    this->preorder(node->rchild);


}


template<typename E>
void BST<E>::inorder(Node<E>* node)//�������
{
    if(node == nullptr)
        return ;
    this->inorder(node->lchild);
    std::cout << node->element <<"  ";
    this->inorder(node->rchild);


}

template<typename E>
void BST<E>::postorder(Node<E>* node)//�������
{
    if(node == nullptr)
        return ;
    this->postorder(node->lchild);
    this->postorder(node->rchild);
    std::cout << node->element << "  ";


}

template<typename E>
void BST<E>::levelorder(Node<E>* node)//��α���
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
int BST<E>::height()//����������������ĸ߶�
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
int BST<E>::height2()//�ݹ���������ĸ߶�
{

    return this->height(root);


}

template<typename E>
int BST<E>::height(Node<E>* node)//�ݹ���������ĸ߶�
{

   if(node == nullptr)
        return 0;
    return std::max(this->height(node->lchild) , this->height(node->rchild)) + 1;


}

template<typename E>
bool BST<E>::isComplete()//�����ж϶������Ƿ�Ϊ��ȫ������
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
void BST<E>::printBst()//��ӡ����������
{
    if(this->root == nullptr)
        return ;
    printBst(root,"");
    

}
template<typename E>
void BST<E>::printBst( Node<E>* node, std::string prefix)// ��ӡ������
{
    if(node == nullptr) return ;
   
    std::cout << prefix << node->element  << std::endl;
    this->printBst(node->lchild , prefix + "L");
    this->printBst(node->rchild , prefix + "R");

}

#endif // ! _BST_H_