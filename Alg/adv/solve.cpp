//
// Created by anton on 10.03.19.
//

#include <iostream>
#define NONE 0
#define INTERSECT_1 1
#define INTERSECT_2 2

using namespace std;

class Section{
public:
    Section();
    Section(int a,int b);
    int intersect(){ return intersect;};
    int length(){ return a-b;}
    int getA(){ return a;};
    int getB(){ return b;};
    bool operator<=(const Section &v1, const Section &v2);
    Section &operator=(Section val);
private:
    int a;
    int b;
    int intersect;
};

bool Section::operator<=(const Section &v1, const Section &v2) {
    if (v1.getA()<=v2.getA()){
        return true;
    } else{
        if (v1.length()>=v2.length()){
            return true;
        }
        return false;
    }
}

Section& Section::operator=(Section &val) {
    Section result;
    result.a=val.getA();
    result.b=val.getB();
    return result;
}

Section::Section() {
    a = 0;
    b = 0;
    intersect=NONE;
}



template <class T> class Vector {
public:
    typedef T *iterator;

    Vector();
    Vector(unsigned int size);
    ~Vector();

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T &front();
    T &back();
    void push_back(const T &value);
    void pop_back();

    void resize(unsigned int size);

    T &operator[](unsigned int index);
    Vector<T> &operator=(const Vector<T> &);
    void clear();

private:
    unsigned int my_size;
    unsigned int my_capacity;
    T *buffer;

    void reserve(unsigned int capacity);
};

// Your code goes here ...
template <class T> Vector<T>::Vector() {
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}

template <class T> Vector<T>::Vector(unsigned int size) {
    my_capacity = size;
    my_size = size;
    buffer = new T[size];
}

template <class T> void Vector<T>::reserve(unsigned int capacity) {
    if (buffer == 0) {
        my_size = 0;
        my_capacity = 0;
    }
    T *Newbuffer = new T[capacity];
    unsigned int l_Size;
    if (capacity < my_size) {
        l_Size = capacity;
    } else {
        l_Size = my_size;
    }

    for (unsigned int i = 0; i < l_Size; i++)
        Newbuffer[i] = buffer[i];

    my_capacity = capacity;
    if (buffer) {
        delete[] buffer;
    }
    buffer = Newbuffer;
}

template <class T> Vector<T> &Vector<T>::operator=(const Vector<T> &v) {
    delete[] buffer;
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
    return *this;
}

template <class T> typename Vector<T>::iterator Vector<T>::begin() {
    return buffer;
}

template <class T> typename Vector<T>::iterator Vector<T>::end() {
    return buffer + size();
}

template <class T> T &Vector<T>::front() { return buffer[0]; }

template <class T> T &Vector<T>::back() { return buffer[my_size - 1]; }

template <class T> void Vector<T>::push_back(const T &v) {
    if (my_size >= my_capacity)
        reserve(my_capacity + 5);
    buffer[my_size++] = v;
}

template <class T> void Vector<T>::pop_back() {
    buffer[my_size - 1] = 0;
    my_size--;
}

template <class T>
unsigned int Vector<T>::size() const //
{
    return my_size;
}

template <class T> T &Vector<T>::operator[](unsigned int index) {
    return buffer[index];
}

template <class T> unsigned int Vector<T>::capacity() const {
    return my_capacity;
}

template <class T> Vector<T>::~Vector() {

    if (my_size && my_capacity) {
        delete[](buffer);
    }
    my_size = 0;
    my_capacity = 0;
}
template <class T> void Vector<T>::clear() {
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}


template <class T>
void merge(Vector<T> &data,int l,int m,int r){
    int size1 = m-l+1;
    int size2= r - m;
    Vector<T> L(size1);
    Vector<T> R(size2);

    for (int i =0;i<size1;i++){
        L[i]=data[i];
    }
    for (int j =0;j<n2;j++){
        R[j]=data[m+1+j];
    }

    i=0;
    j=0;
    int k =1;

    while (i<n1 && j<n2){
        if (L[i]<=R[j]){
            data[k]=L[i];
            i++;
        } else{
            data[k]=R[j];
            j++;
        }
        k++;
    }

    while (i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }

    while (j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }

}
void mergeSort(Vector<Section> &data,int a,int b){
    if (a>b){
        int m = a+(b-a)/2;
        mergeSort(data,a,m);
        mergeSort(data,m+1,b);
        merge(data,a,m,r);
    }
}

void scan(Vector<Section> &data,int n){
    for (int i=0;i<n;i++){
        int a=0,b=0;
        cin>>a>>b;
        data[i]=Section(a,b);
    }
}


int main(){
    int n=0;
    cin>>n;
    Vector<Section> data= new Vector<Section>(n);
    scan(data);
    mergeSort(data,0,data.size());
    for (int i =0;i<n;i++){
        cout<<data[i].getA()<<" "<<data[i].getB()<<endl;
    }
}