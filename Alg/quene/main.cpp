#include <iostream>

//В круг выстроено N человек, пронумерованных числами от 1 до N.
// Будем исключать каждого k-ого до тех пор, пока не уцелеет только один человек.
//Например, если N=10, k=3, то сначала умрет 3-й, потом 6-й, затем 9-й, затем 2-й, затем 7-й, потом 1-й, потом 8-й, за ним - 5-й, и потом 10-й.
// Таким образом, уцелеет 4-й.
//Необходимо определить номер уцелевшего.
//N, k ≤ 10000.
template <class T> class Vector {
public:
    typedef T *iterator;

    Vector();
    Vector(unsigned int size);
    ~Vector();

    unsigned int capacity() const;
    unsigned int size() const;

    iterator begin();
    iterator end();
    T &front();
    T &back();
    void push_back(const T &value);
    void pop_back();


    T &operator[](unsigned int index);
    Vector<T> &operator=(const Vector<T> &);
    void clear();

private:
    unsigned int my_size;
    unsigned int my_capacity;
    T *buffer;

    void reserve(unsigned int capacity);
};


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

void move(const int N,const int K,Vector<int> &list,int &size,int &count){

    for (int i=0;i<K;i++){
        int j=1;
        if (count>=N-1){
            count-=N;
        }
        int buf=count+j;
        while (list[buf]==-1){
            j++;
            buf = count+j;
            if (buf>=N){
                buf-=N;
            }
        }
        count=buf;
    }//Перемещаемся к следующему живому
    list[count]=-1;
    size--;
}

Vector<int> init(int &K,int &N,int &size){
    std::cin>>N>>K;
    Vector<int> list(N);
    for (int i =0;i<N;i++){
        list[i]=i;
    }
    size=N;
    return list;

}

void printResult(Vector<int> &list){
    for(int i:list){
        if (i!=-1){
            std::cout<<i+1;
        }
    }
}



int main() {
    int N=0,K=0,size=0,count=-1;
    Vector<int> list =  init(K,N,size);
    while (size>=2){
        move(N,K,list,size,count);
    }
    printResult(list);
    return 0;
}