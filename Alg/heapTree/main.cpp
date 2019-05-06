#include <iostream>
#include <assert.h>
#include <math.h>
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
    void Add(const T value);
    void Delete(const T value);
    bool Contains(const T value);
    Node<T> *getTree() const;

    int maxDepth();
    Node<T>* getMin(Node<T>*tree,Node<T>*& minParent);
    BinaryTree();
    ~BinaryTree();
private:
    int getDepth(Node<T>* root);
    Node<T>* findWithNode(T value,Node<T>*& parent);
    void deleteNode(Node<T>*& node);
    Node<T>* tree;
};

template<class T>
int BinaryTree<T>::maxDepth() {
    return getDepth(tree);
}
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
Node<T> *BinaryTree<T>::getTree() const {
    return tree;
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

template<class T>
int BinaryTree<T>::getDepth(Node<T> *root) {
    if (root == nullptr)
        return 0;

    std::queue<Node<T>*> q;

    q.push(root);
    int height = 0;

    while (1)
    {
        int nodeCount = q.size();
        if (nodeCount == 0) {
            return height;
        }

        height++;

        while (nodeCount > 0)
        {
            Node<T> *node = q.front();
            q.pop();
            if (node->getLeftChild() != nullptr)
                q.push(node->getLeftChild());
            if (node->getRightChild() != nullptr)
                q.push(node->getRightChild());
            nodeCount--;
        }
    }
}


template <class T>
class TreeNode{
public:
    TreeNode(T x, T y) : x(x), y(y) {}
    TreeNode() ;
    void setRight(TreeNode<T> *right) { TreeNode::right = right; }
    void setLeft(TreeNode<T> *left) { TreeNode::left = left; }

    T x;
    T y;
    TreeNode<T>* right;
    TreeNode<T>* left;
};

template<class T>
TreeNode<T>::TreeNode() {

}


template <class T>
class HeapTree{
public:


    HeapTree(){root= nullptr;}
    void add(const T &x, const T &y);
    int maxDepth();

    ~HeapTree();

private:
    TreeNode<T> *getRoot() const;
    int getDepth(TreeNode<T>* root);
    void split(TreeNode<T>* root,T x, TreeNode<T> *&left, TreeNode<T> *&right);
    HeapTree<T>* merge(TreeNode<T> *&left, TreeNode<T> *&right);
    TreeNode<T>* add(TreeNode<T> *&root,const T &x, T const &y);
    TreeNode<T>* root;

};

template<class T>
void HeapTree<T>::split(TreeNode<T>* root,T x, TreeNode<T> *&left, TreeNode<T> *&right) {
    if (root == nullptr){
        left = nullptr;
        right = nullptr;
    } else if (x >= root->x){
        split(root->right,x, root->right, right);
        left = root;
    } else{
        split(root->left,x, left, root->left);
        right = root;
    }
}

template<class T>
HeapTree<T> *HeapTree<T>::merge(TreeNode<T> *&left, TreeNode<T> *&right) {
    if (left == nullptr || right == nullptr){
        return left==0 ? right:left;
    }
    if (left->y>right->y){
        left->right= merge(left->right, right);
        return left;
    } else{
        right->left = merge(right->left, left);
        return right;
    }
}

template<class T>
TreeNode<T>* HeapTree<T>::add(TreeNode<T> *&root,const T &x, const T &y) {

    if (root == nullptr){
        root=new TreeNode<T>(x,y);;
        return nullptr;
    }

    if(root->y>=y){
        if (x<root->x){
            add(root->left,x,y);
        } else{
            add(root->right,x,y);
        }
    } else{
        auto * node = new TreeNode<T>(x,y);
        TreeNode<T>* T1;
        TreeNode<T>* T2;
        split(root,x,T1,T2);
        node->setLeft(T1);
        node->setRight(T2);
        root=node;

    }

}

template<class T>
void HeapTree<T>::add(const T &x,const  T &y) {

    if (root == nullptr){
        root=new TreeNode<T>(x,y);;
        return;
    }

    if(root->y>=y){
        if (x<root->x){
            add(root->left,x,y);
        } else{
            add(root->right,x,y);
        }
    } else {
        auto * node = new TreeNode<T>(x,y);
        TreeNode<T>* T1;
        TreeNode<T>* T2;
        split(root,x,T1,T2);
        node->setLeft(T1);
        node->setRight(T2);
        root=node;
    }

}

template<class T>
TreeNode<T> *HeapTree<T>::getRoot() const {
    return root;
}

template<class T>
int HeapTree<T>::maxDepth() {
    return getDepth(getRoot());
}

template<class T>
int HeapTree<T>::getDepth(TreeNode<T> *root) {
    if (root == nullptr)
        return 0;

    std::queue<TreeNode<T>*> q;

    q.push(root);
    int height = 0;

    while (1)
    {
        int nodeCount = q.size();
        if (nodeCount == 0) {
            return height;
        }

        height++;

        while (nodeCount > 0)
        {
            TreeNode<T> *node = q.front();
            q.pop();
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
            nodeCount--;
        }
    }
}

template<class T>
HeapTree<T>::~HeapTree() {
    if (root == nullptr)
        return;


    std::queue<TreeNode<T>*> q;


    q.push(root);
    while (!q.empty())
    {
        TreeNode<T>* node= q.front();
        q.pop();

        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);

        delete(node);
    }
}


int main() {
    HeapTree<int> tree;
    BinaryTree<int> binaryTree;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        tree.add(x, y);
        binaryTree.Add(x);
    }

    std::cout << abs(tree.maxDepth() - binaryTree.maxDepth());

    return 0;
}