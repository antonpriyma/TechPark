//
// Created by anton on 10.03.19.
//

#include <iostream>
#include <assert.h>


//В супермаркете решили оптимизировать показ рекламы.
//Известно расписание прихода и ухода покупателей (два целых числа).
//Каждому покупателю необходимо показать минимум 2 рекламы.
//Рекламу можно транслировать только в целочисленные моменты времени.
//Покупатель может видеть рекламу от момента прихода до момента ухода из магазина.
//В каждый момент времени может показываться только одна реклама.
//Считается, что реклама показывается мгновенно.
//Если реклама показывается в момент ухода или прихода, то считается, что посетитель успел её посмотреть.
//Требуется определить минимальное число показов рекламы.


class Section{
public:
    Section();
    Section(int a,int b);
    int length(){ return b-a;}
    int getA()const { return a;};
    int getB()const { return b;};
    bool operator<=(Section &v2);
    // Section &operator=(Section &val);
private:
    int a;
    int b;
};

bool Section::operator<=(Section &v2) {
    if (this->getB()<v2.getB()){
        return true;
    }
    if (this->getB()==v2.getB()){
        return this->getA() > v2.getA();
    }
    return false;
}

int compareSections(const Section &a,const Section &b){
    if (a.getB()<b.getB()){
        return -1;
    }
    if (a.getB()==b.getB()){
        if (a.getA()>b.getA()){
            return -1;
        } else if (a.getA()==b.getA()){
            return 0;
        }
        return 1;
    }
    return 1;
}


Section::Section() {
    a = 0;
    b = 0;
}

Section::Section(int a, int b) {
    this->a=a;
    this->b=b;
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

template<class T>
bool Vector<T>::empty() const {
    return size()==0;
}

template <class T>
void merge(T* data,unsigned int l,unsigned int m,int r,int (*compare)(const T &a,const T&b)){
    assert(l>=0 && l<r );
    unsigned int size1 = m - l + 1;
    unsigned int size2= r - m;
    Vector<Section> L(size1);
    Vector<Section> R(size2);

    for (int i =0;i<size1;i++){
        L[i]=data[l+i];
    }
    for (int j =0;j<size2;j++){
        R[j]=data[m+1+j];
    }

    int i=0;
    int j=0;
    int k =l;

    while (i<size1 && j<size2){
        if (compare(L[i],R[j])==-1){
            data[k]=L[i];
            i++;
        } else{
            data[k]=R[j];
            j++;
        }
        k++;
    }

    while (i<size1){
        data[k]=L[i];
        i++;
        k++;
    }

    while (j<size2){
        data[k]=R[j];
        j++;
        k++;
    }

}

template <class T>
void mergeSort(T* data,unsigned int l,unsigned int r,int (*compare)(const T &a,const T&b)){
    assert(l>=0);
    if (l<r){
        unsigned int m = l+(r-l)/2;
        mergeSort(data,l,m,compare);
        mergeSort(data,m+1,r,compare);
        merge(data,l,m,r,compare);
    }
}

void scan(Vector<Section> &data){
    for (auto &i : data) {
        int a=0,b=0;
        std::cin>>a>>b;
        i =Section(a,b);
    }
}

unsigned int findMin(Vector<Section> &data){
    mergeSort(data.begin(),0,data.size()-1,compareSections);
    unsigned minAdv = 0;
    int endOfFrontSegment = -1;
    int beginOfFrontSegment = -1;
    for (auto &i : data) {
        if (i.getA() > endOfFrontSegment) {
            endOfFrontSegment = i.getB();
            beginOfFrontSegment = endOfFrontSegment - 1;
            minAdv += 2;
        } else if (i.getA() == endOfFrontSegment ||
                   ((i.getA() > beginOfFrontSegment) &&
                    (i.getB() > endOfFrontSegment))) {
            beginOfFrontSegment = endOfFrontSegment;
            endOfFrontSegment = i.getB();
            minAdv++;
        }
    }

    return minAdv;
}

int main(){
    unsigned int n=0,result=0;
    std::cin>>n;
    Vector<Section> data(n);
    scan(data);


    result=findMin(data);
    std::cout<<result;
    return 0;

}