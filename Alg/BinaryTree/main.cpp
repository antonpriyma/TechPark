#include <iostream>
#include <vector>
#include <assert.h>
#include <stack>
#include <queue>

template <class T>
class Node{
public:
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


    T getData() const {
        return Data;
    }



private:
    Node<T> *rightChild;
    Node<T> *leftChild;
    T Data;
};


template <class T>
class BinaryTree{
public:
    void Add(const T &value);
    void Delete(const T &value);
    bool Contains(const T &value);
    std::vector<T> postOrderPrint();

    BinaryTree();
    ~BinaryTree();

private:
    Node<T>* findWithNode(T value,Node<T>*& parent);
    Node<T>* getMin(Node<T>*tree,Node<T>*& minParent);
    void deleteNode(Node<T>*& node);
    Node<T>* tree;
};

template<class T>
void BinaryTree<T>::Add(const T &value) {
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
bool BinaryTree<T>::Contains(const T &value) {
    Node<T>* parent;
    return findWithNode(value,parent)!= nullptr;

}

template<class T>
void BinaryTree<T>::Delete(const T &value) {
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
std::vector<T> BinaryTree<T>::postOrderPrint() {
    std::stack<Node<T>*> stack;
    std::vector<T> result;
    Node<T>* node = tree;
    do{
        while (node)
        {
            if (node->getRightChild())
                stack.push(node->getRightChild());
            stack.push(node);
            node = node->getLeftChild();
        }

        node = stack.top();
        stack.pop();

        if (!stack.empty() && node->getRightChild() && stack.top()== node->getRightChild())
        {
            stack.pop();
            stack.push(node);
            node=node->getRightChild();
        }
        else
        {
            result.push_back(node->getData());
            node = nullptr;
        }
    }while (!stack.empty());
    return result;

}



template<class T>
BinaryTree<T>::~BinaryTree() {
    if (tree == nullptr)
        return;
    std::queue<Node<T>*> q;

    q.push(tree);
    while (!q.empty())
    {
        Node<T>* node = q.front();
        q.pop();

        if (node->getLeftChild()!= NULL)
            q.push(node->getLeftChild());
        if (node->getRightChild() != NULL)
            q.push(node->getRightChild());

        delete(node);
    }
}

int main() {
    BinaryTree<int> tree;
    int n=0;
    std::cin>>n;
    for (int i =0;i<n;i++){
        int value;
        std::cin>>value;
        tree.Add(value);
    }

    std::vector<int> result = tree.postOrderPrint();
    for (auto i:result){
        std::cout<<i<<" ";
    }

    return 0;
}