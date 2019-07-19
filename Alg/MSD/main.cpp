#include <iostream>
#include <assert.h>

#define MAX_SIZE 64


//Дан массив неотрицательных целых 64-разрядных чисел.
//Количество чисел не больше 1000000.
//Отсортировать массив методом MSD по битам (бинарный QuickSort).


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
    void swap(unsigned int i,unsigned int j);
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
    return this->size()==0;
}

template<class T>
void Vector<T>::swap(unsigned int i, unsigned int j) {
    assert(i>=0 && i<size() && j>=0 && j<size());
    T buf = this->buffer[i];
    this->buffer[i]=this->buffer[j];
    this->buffer[j]=buf;
}


long long getByte(long long value, int position, unsigned int maxSize)
{
    assert(position>=0);
    return (value>>maxSize-position-1)&1;
}


template <class T>
void quickSortByte(T *a, int l, int r, int d, unsigned int maxSize) {
    int i = l, j = r;
    if (r <= l || d > maxSize) return;
    while (j > i) {
        while (getByte(a[i], d,maxSize) == 0 && (i < j)) i++;
        while (getByte(a[j], d, maxSize) == 1 && (j > i)) j--;
        T temp = a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    if (getByte(a[r], d,maxSize) == 0) {
        j++;
    }

    quickSortByte(a, j, r, d + 1, maxSize);
    quickSortByte(a, l, j - 1, d + 1, maxSize);
}
template <class T>
void sort(T *a, int l, int r,unsigned int maxSize) {
    quickSortByte(a, l, r - 1, 0, maxSize);
}

Vector<long long> scan(int n){
    Vector<long long > result(n);
    for(int i = 0;i<n;i++){
        std::cin>>result[i];
    }
    return result;
}

int main() {
    int n;
    std::cin>>n;
    Vector<long long > data = scan(n);
    sort(data.begin(),0,data.size(),MAX_SIZE);
    for (long long i : data) {
        std::cout<< i <<" ";
    }

    return 0;
}

//001...0000000
//
//
//000...100

