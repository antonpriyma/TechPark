#include <iostream>

#define POP 2
#define PUSH 3
#define YES "YES"
#define NOT "NO"

using namespace std;

class Stack{
public:

    Stack(int n);
    Stack(int *arr);
    void push(int x);
    int pop();
    bool checkEmpty();
    int getTop();
    int getCap();
    int* getData();
    void setTop(int top);
    void setCap(int cap);


private:
    int *data;
    int top;
    int cap;
};

Stack::Stack(int n) {
    int *buf = (int *)malloc(n* sizeof(int));
    if (!buf){
        cout<<"Error";
        return;
    }
    data=buf;
    top=0;
    cap=n;

}
bool Stack::checkEmpty() {
    if (top==0){
        return true;
    }
    return false;
}
void Stack::push(int x) {
    if (top==cap){
        cout<<"Out of heap";
        return;
    } else{
        data[top++]=x;
    }
}

int Stack::pop(){
    return data[top--];
}

int Stack::getCap() {
    return cap;
}

int Stack::getTop() {
    return top;
}

void Stack::setTop(int top) {
    this->top=top;
}

void Stack::setCap(int cap) {
    this->cap=cap;
}

Stack::Stack(int *arr) {
    if (arr){
        this->data=arr;
    }
}

int* Stack::getData() {
    return data;
}

class Quene{
public:


    Quene(int n);
    int pop();
    void push(int x);
    bool checkEmpty();
    bool doCommand(int command,int value);
private:
    Stack *stack1;
    Stack *stack2;
};

Quene::Quene(int n) {
    stack1=new Stack(n);
    stack2=new Stack(stack1->getData());
}

bool Quene::checkEmpty() {
    return stack1->getTop() == stack2->getTop();
}

int Quene::pop() {
    if (!checkEmpty()){
        int x=stack2->pop();
        stack2->setTop(stack2->getTop()+2);
        return x;
    } else{
        return -1;
    }
}

void Quene::push(int x) {
    stack1->push(x);
}

bool Quene::doCommand(int command, int value) {
    switch (command){
        case POP:
            return pop()==value;
        case PUSH:
            push(value);
            break;
    }
    return true;
}

int main() {
    int n=0;
    cin>>n;
    bool ok = true;
    Quene *quene=new Quene(n);
    for (int i=0;i<n;i++){
        int command=0,value=0;
        cin>>command>>value;
        if (!quene->doCommand(command,value)){
            ok = false;
        }
    }
    if (ok){
        cout<<YES;
    } else{
        cout<<NOT;
    }


    delete(quene);
    return 0;
}