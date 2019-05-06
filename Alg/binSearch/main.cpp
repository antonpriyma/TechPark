#include <iostream>
#include <assert.h>


//Дан отсортированный массив целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
//Для каждого элемента массива B[i] найдите минимальный индекс k минимального элемента массива A, равного или превосходящего B[i]: A[k] >= B[i].
//Если такого элемента нет, выведите n.
//Время работы поиска k для каждого элемента B[i]: O(log(k)). n, m ≤ 10000.




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
    void print();
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
void Vector<T>::print() {
    for (int i =0;i<size();i++){
        std::cout<<buffer[i]<<" ";
    }
}


void scan(Vector<int> &a,Vector<int> &b,int n ,int m){
    for (int i =0;i<n;i++){
        std::cin>>a[i];
    }
    getchar();
    for (int i =0;i<m;i++){
        std::cin>>b[i];
    }
}

int binSearch(Vector<int> &array, int key, int size){
    assert(size>0);
    int start = 0,end = size,mid=0,i=1;

    while(i<=size && array[i]<key){
        i*=2;
    }
    if (i>size){
        i=size;
    }
    int ans = i+1;
    end=i;
    start=i/2;
    while (start <= end){
        mid = start + (end-start)/2;
        if (array[start] == key)
            return start;


        if (array[mid]>=key){
            ans=mid;
            end=mid-1;
        } else {
            start=mid+1;
        }
    }
    return ans;
}

Vector<int> findPositions(Vector<int> &a,Vector<int> &b){
    Vector<int> result;
    for(int i =0;i<b.size();i++){
        result.push_back(binSearch(a, b[i], a.size() - 1));
    }
    return result;
}



int main() {
    int n=0,m=0;
    std::cin>>n>>m;
    Vector<int> a(n),b(m);
    scan(a,b,n,m);
    findPositions(a,b).print();
    return 0;
}