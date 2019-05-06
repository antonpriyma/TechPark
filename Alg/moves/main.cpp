#include <iostream>

#define POP 2
#define PUSH 3
#define YES "YES"
#define NOT "NO"

//Реализовать очередь с помощью двух стеков. Использовать стек, реализованный с помощью динамического буфера.
//
//Обрабатывать команды push back и pop front.

template <class T>
class Stack{
public:

    Stack(int n);
    Stack(T *arr,int n);
    void push(T x);
    T pop();
    bool checkEmpty();
    int getTop();
    int getCap();
    T* getData();
    void setTop(int top);
    ~Stack();
    void setCap(int cap);


private:
    T *data;
    int top;
    int cap;
};

template <class T>
Stack<T>::Stack(int n) {
    T *buf = new T[n];
    data=buf;
    top=0;
    cap=n;
}

template <class T>
Stack<T>::Stack(T *arr,int n) {
    if (arr){
        this->data=arr;
    }
    cap=n;
    top=0;
}

template <class T>
bool Stack<T>::checkEmpty() {
    if (top==0){
        return true;
    }
    return false;
}

template <class T>
void Stack<T>::push(T x) {
    if (top==cap){
        int* buf = new int[top*2];
        for (int i=0;i<cap;i++){
            buf[i]=data[i];
        }
        delete[](data);
        return;
    } else{
        data[top++]=x;
    }
}

template <class T>
T Stack<T>::pop(){
    return data[top--];
}

template <class T>
int Stack<T>::getCap() {
    return cap;
}

template <class T>
int Stack<T>::getTop() {
    return top;
}

template <class T>
void Stack<T>::setTop(int top) {
    this->top=top;
}

template <class T>
void Stack<T>::setCap(int cap) {
    this->cap=cap;
}


template <class T>
T* Stack<T>::getData() {
    return data;
}

template <class T>
Stack<T>::~Stack() {
    delete[](data);
}

template <class T>
class Quene{
public:


    Quene(int n);
    T pop();
    void push(T x);
    bool checkEmpty();
    bool doCommand(int command,int value);
    ~Quene();
private:
    Stack<T> *stack1;
    Stack<T> *stack2;
};

template <class T>
Quene<T>::Quene(int n) {
    stack1=new Stack<T>(n);
    stack2=new Stack<T>(stack1->getData(),n);
}

template <class T>
bool Quene<T>::checkEmpty() {
    return stack1->getTop() == stack2->getTop();
}

template <class T>
T Quene<T>::pop() {
    if (!checkEmpty()){
        T x=stack2->pop();
        stack2->setTop(stack2->getTop()+2);
        return x;
    } else{
        return -1;
    }
}

template <class T>
void Quene<T>::push(T x) {
    stack1->push(x);
}

template <class T>
bool Quene<T>::doCommand(int command, int value) {
    switch (command){
        case POP:
            return pop()==value;
        case PUSH:
            push(value);
            break;
    }
    return true;
}

template <class T>
Quene<T>::~Quene() {
    delete(stack1);
}

int main() {
    int n=0;
    std::cin>>n;
    bool ok = true;
    Quene<int> *quene=new Quene<int>(n);
    for (int i=0;i<n;i++){
        int command=0,value=0;
        std::cin>>command>>value;
        if (!quene->doCommand(command,value)){
            ok = false;
        }
    }
    if (ok){
        std::cout<<YES;
    } else{
        std::cout<<NOT;
    }


    delete(quene);
    return 0;
}