#include <iostream>

#define POP 2
#define PUSH 3
#define YES "YES"
#define NOT "NO"

using namespace std;

class Stack{
public:
    int *data;
    int top;
    int cap;
    Stack(int n);
    void push(int x);
    int pop();
    bool checkEmpty();


private:
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

class Quene{
public:
    Stack *stack1;
    Stack *stack2;

    Quene(int n);
    int pop();
    void push(int x);
    bool checkEmpty();
    bool doCommand(int command,int value);
private:
};

Quene::Quene(int n) {
    stack1=new Stack(n);
    stack2=new Stack(n);
    free(stack2->data);
    stack2->data=stack1->data;
}

bool Quene::checkEmpty() {
    return stack1->top == stack2->top;
}

int Quene::pop() {
    if (!checkEmpty()){
        int x=stack2->pop();
        stack2->top+=2;
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