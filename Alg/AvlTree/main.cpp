#include <iostream>
#include <assert.h>
#include <stack>
#include <vector>
#include <queue>

template <class T>


struct Node{
    T key;
    unsigned int height;
    unsigned int leftCount;
    unsigned int rightCount;
    Node<T>* right;
    Node<T>* left;

    Node(T key) : key(key) {left= nullptr,right= nullptr,height=1;}



    void updateHeight(){
        int lHeight = 0;
        int rHeight = 0;
        if (left != nullptr) {
            lHeight = left->height;
        }
        if (right != nullptr) {
            rHeight = right->height;
        }
        int max = (lHeight > rHeight) ? lHeight : rHeight;
        height = max + 1;
        leftCount = left == nullptr
                         ? 0
                         : (left->leftCount + left->rightCount + 1);
        rightCount = right == nullptr
                          ? 0
                          : (right->leftCount + right->rightCount + 1);
    }






};

template <class T>
int getHeight(Node<T>* node){
    return node?node->height:0;
}

template <class T>
int bFactor(Node<T>* node){
    return getHeight(node->right)-getHeight(node->left);
}




template <class T>
class AvlTree{
public:
    void add(const T key);
    void remove(const T key);
    T getKStat(int k);
    AvlTree(){root= nullptr;}
    ~AvlTree();

private:
    void insert(T key, Node<T>*& node);
    Node<T>* rotateLeft(Node<T> *&node);
    Node<T>* rotateRight(Node<T> *&node);
    Node<T>* balance(Node<T> *&node);
    Node<T> * deleteNode(T key, Node<T> *&node);

    Node<T>* root;


    Node<T>* removeMin(Node<T> *node);
    Node<T> *getMin(Node<T> *tree);
};

template<class T>
Node<T> *AvlTree<T>::rotateRight(Node<T> *&node) {
    Node<T>* result = node->left;
    node->left = result->right;
    result->right = node;
    node->updateHeight();
    result->updateHeight();
    return result;
}

template<class T>
Node<T> *AvlTree<T>::rotateLeft(Node<T> *&node) {
    Node<T>* result = node->right;
    node->right = result->left;
    result->left = node;
    node->updateHeight();
    result->updateHeight();
    return result;
}

template<class T>
Node<T> *AvlTree<T>::balance(Node<T> *&node) {
    node->updateHeight();
    if( bFactor(node)==2 )
    {
        if( bFactor(node->right)< 0 )
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    if(bFactor(node)==-2 )
    {
        if(bFactor(node->left)> 0  )
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    return node;
}

template<class T>
void AvlTree<T>::insert(T key,Node<T> *&node) {
    if (node == nullptr){
        node = new Node<T>(key);
        node->updateHeight();
    }
    else {
        if (key < node->key){
            insert(key, node->left);
            node->updateHeight();
            node = balance(node);
        }
        else{
            insert(key, node->right);
            node->updateHeight();
            node = balance(node);
        }
    }

}

template<class T>
void AvlTree<T>::add(const T key) {
    insert(key,root);
}

template<class T>
Node<T>* AvlTree<T>::getMin(Node<T>* tree) {
    assert(tree!= nullptr);
    Node<T>* node = tree;
    while (node->left!= nullptr){
        node=node->left;
    }
    return node;
}

template<class T>
Node<T> *AvlTree<T>::removeMin(Node<T> *node) {
    //Проходимся по вершинам, балансируем
    if (node->left == nullptr) {
        return node->right;
    }
    node->left = removeMin(node->left);
    return balance(node);
}

template<class T>
Node<T>* AvlTree<T>::deleteNode(T key, Node<T> *&node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (key < node->key) {
        node->left = deleteNode(key, node->left);
    } else if (key > node->key) {
        node->right = deleteNode(key, node->right);
    } else {
        Node<T>* leftNode = node->left;
        Node<T>* rightNode = node->right;
        if (rightNode == nullptr) {
            return leftNode;
        }
        //Находим минимум
        Node<T>* min_node = getMin(rightNode);
        min_node->right = removeMin(rightNode);
        min_node->left = leftNode;
        return balance(min_node);
    }
    return balance(node);
}

template<class T>
void AvlTree<T>::remove(const T key) {
    root = deleteNode(key, root);
}

template<class T>
T AvlTree<T>::getKStat(int k) {
    assert(k <= (root->leftCount + root->rightCount));
    Node<T>* node = root;
    while(k!=node->leftCount) {

        if (node->leftCount< k) {
            k -= node->leftCount;
            k--;
            node = node->right;
        }
        else {
            node = node->left;
        }
    }
    return node->key;
}

template<class T>
AvlTree<T>::~AvlTree() {
    if (root == nullptr)
        return;
    std::queue<Node<T>*> q;

    q.push(root);
    while (!q.empty())
    {
        Node<T>* node = q.front();
        q.pop();

        if (node->left!= nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);

        delete(node);
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
    AvlTree<int> tree;
    int n=0;

    std::cin>>n;
    std::vector<std::pair<int,int>> data=scan(n);
    for (int i = 0;i<n;i++){
        if (data[i].first>0){
            tree.add(data[i].first);
        } else{
           tree.remove(-data[i].first);
        }
        int result = tree.getKStat(data[i].second);
        std::cout<<result<<" ";
    }
    return 0;
}