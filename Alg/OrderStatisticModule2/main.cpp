#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>



template <class T>
class Node{
public:
    Node(T Data,Node<T> *rightChild, Node<T> *leftChild,int rank) : rightChild(rightChild),
                                                           leftChild(leftChild),
                                                           Data(Data),rank(rank){};

    Node(T Data,Node<T> *rightChild, Node<T> *leftChild) : rightChild(rightChild),
                                                                    leftChild(leftChild),
                                                                    Data(Data){};

    Node<T> *getRightChild() const {
        return rightChild;
    }

    Node<T> *getLeftChild() const {
        return leftChild;
    }

    void setRightChild(Node<T> *rightChild) {
        Node::rightChild = rightChild;
    }

    void setLeftChild(Node<T> *leftChild) {
        Node::leftChild = leftChild;
    }

    void setData(T Data) {
        Node::Data = Data;
    }

    int getRank() const;

    void setRank(int rank);

    T getData() const {
        return Data;
    }

    ~Node();

private:
    Node<T> *rightChild;
    Node<T> *leftChild;
    T Data;
    int rank;
};

template<class T>
Node<T>::~Node() {
    delete(leftChild);
    delete(rightChild);
}

template<class T>
void Node<T>::setRank(int rank) {
   this->rank = rank;
}

template<class T>
int Node<T>::getRank() const {
    return rank;
}

template <class T>
class BinaryTree{
public:
    void Add(T value);
    void Delete(T value);
    void DeleteNode(Node<T>*& node);
    bool Contains(T value);
    void postOrderPrint();
    void preOrderPrint();
    void levelOrderPrint();
    void inOrderPrint();
    void assignRank(Node* root);
    Node<T>* getMin(Node<T>* node,Node<T>*& minParent);
    BinaryTree(){count=0;};
    ~BinaryTree();
    T getSelect(Node<T> *root,int k);

private:
    Node<T>* findWithNode(T value,Node<T>*& parent);
    void deleteNode(Node<T>*& node);
    Node<T>* tree;
    int count;
};

template<class T>
void BinaryTree<T>::Add(T value) {
    //Дерево пустое
    if (!tree){
        tree = new Node<T>(value, nullptr, nullptr);
        return;
    }
    Node<T>* vertex= tree;
    while(1) {
        if (value < vertex->getData()) {
            if (vertex->getLeftChild() == nullptr) {
                vertex->setLeftChild(new Node<T>(value, nullptr, nullptr));
                break;
            } else {
                vertex = vertex->getLeftChild();
            }
        } else {
            if (vertex->getRightChild() == nullptr) {
                vertex->setRightChild(new Node<T>(value, nullptr, nullptr));
                break;
            } else {
                vertex= vertex->getRightChild();
            }
        }
    }
}

template<class T>
bool BinaryTree<T>::Contains(T value) {
    Node<T>* parent;
    return findWithNode(value,parent)!= nullptr;

}

template<class T>
void BinaryTree<T>::Delete(T value) {
    Node<T> *node,*parent;
    node = findWithNode(value,parent);
    if (node == nullptr){
        return;
    }
    while(1) {
        if (value > node->getData()) {
            node = node->getRightChild();
        } else if (value < node->getData()) {
            node = node->getLeftChild();
        } else if (value == node->getData()) {
            deleteNode(node);
            break;
        }
    }

}

template<class T>
Node<T>* BinaryTree<T>::getMin(Node<T>* tree,Node<T>*& minParent) {
//    Node<T>* node = tree;
    assert(tree!= nullptr);
    Node<T>* node = tree;
    while (node->getLeftChild()!= nullptr){
        minParent=node;
        node=node->getLeftChild();
    }
    return node;
}


template<class T>
Node<T>* BinaryTree<T>::findWithNode(T value,Node<T>*& parent) {
    Node<T>* node = tree;
    parent= nullptr;
    while (node!= nullptr){
        if (value>node->getData()){
            parent=node;
            node = node->getRightChild();
        } else if (value<node->getData()){
            parent=node;
            node = node->getLeftChild();
        } else{
            break;
        }
    }
    return node;

}

template<class T>
void BinaryTree<T>::deleteNode(Node<T> *&node) {
    if (node->getLeftChild()== nullptr){
        Node<T>* right = node->getRightChild();
        delete node;
        node = right;
    } else if (node->getRightChild() == nullptr){
        Node<T>* left = node->getLeftChild();
        delete node;
        node =left;
    } else{
        Node<T>* minParent = node;
        Node<T>* min= node->getRightChild();
        min = getMin(min,minParent);
        if (min == node->getRightChild()){
            node->setData(min->getData());
            node->setRightChild(min->getRightChild());
            delete(min);
        } else{
            node->setData(min->getData());
            minParent->setLeftChild(min->getRightChild());
            delete(min);
        }
    }
}

template<class T>
BinaryTree<T>::BinaryTree() {
    tree= nullptr;
}


template<class T>
BinaryTree<T>::~BinaryTree() {
    delete(tree);
}

template<class T>
void BinaryTree<T>::assignRank(Node* root) {
    if(root->getLeftChild() != NULL)
        assignRank(root->getLeftChild());

    root->setRank(count);
    count++;

    if(root->getRightChild() != NULL)
        assignRank(root->getRightChild());
}



template<class T>
T BinaryTree<T>::getSelect(Node<T> *root,int k) {
    if(root->getRank()== k)
        return root->getData();
    else if(root->getRank() > k)
        return getSelect(root->getLeftChild(), k);
    else
        return getSelect(root->getRightChild(), k);
}


int compareInts(const int &a, const int &b){
    if (a>b){
        return 1;
    }
    if (a<b){
        return -1;
    }
    return 0;
}

template <class T>
void swap(std::vector<T> &a, int i,int j){
    T temp = a[i];
    a[i]=a[j];
    a[j]=temp;
}

template<class T>
unsigned int partition(std::vector<T> &data,unsigned int l,unsigned int r,int (*compare)(const T &a, const T &b)){
    assert(l>=0 );
    int i = l,j = r;
    unsigned int midIndex=(l+r)/2;
    T mid = data[midIndex];
    swap(data,midIndex,r);
    i=-1;
    j=0;
    while (j<r && j>i){

        while (compare(data[j],mid)==1){
            j++;
        }
        if (j>=r || i>j) {
            break;
        }
        swap(data,++i,j++);
    }
    swap(data,++i,r);
    return i;
}

template<class T>
int findOrderStatistic(std::vector<T> data,int n,unsigned int k,int (*compare)(const T &a, const T &b)){
    unsigned int left = 0,right = n;
    while (true){
        unsigned int mid = partition(data,left,right,compare);
        if (mid==k){
            return data[mid];
        } else if (mid>k){
            right=mid;
        } else if (mid<k){
            left=mid+1;
        }
    }
}


std::vector<std::pair<int,int>> scan(unsigned int n){
    std::vector<std::pair<int,int>> data(n);
    for (int i = 0;i<n;i++){
        std::cin>>data[i].first>>data[i].second;
    }
    return data;
}

int main() {
    unsigned  int n ;
    BinaryTree<int> values;
    std::cin>>n;
    std::vector<std::pair<int,int>> data=scan(n);
    for (int i = 0;i<n;i++){
        if (data[i].first>0){
            values.Add(data[i].first);
        } else{
            values.Delete(-data[i].second);
        }
        int result = values.getSelect()
        std::cout<<result<<" ";
    }
}

//1 4 3 5
//
//1 5 3 4
//1 3 5 4

