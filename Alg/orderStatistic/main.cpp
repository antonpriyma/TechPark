#include <iostream>
#include <assert.h>

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

//template<class T>
//std::ostream &Vector<T>::operator<<(std::ostream &stream, const Vector<T> &v) {
//    for (int i =0;i<v.size();i++){
//        stream<<v[i];
//    }
//    return stream;
//}

int compareInts(const int &a, const int &b){
    if (a>b){
        return 1;
    }
    if (a<b){
        return -1;
    }
    return 0;
}

template <class T>
void swap(T* a, int i,int j){
    T temp = a[i];
    a[i]=a[j];
    a[j]=temp;
}

template<class T>
unsigned int partition(T *data,unsigned int l,unsigned int r,int (*compare)(const T &a, const T &b)){
    assert(l>=0 );
    int i = l,j = r;
    unsigned int midIndex=(l+r)/2;
    T mid = data[midIndex];
    swap(data,midIndex,r);
    i=-1;
    j=0;
    while (j<r && j>i){

        while (compare(data[j],mid)==1){
            j++;
        }
        if (j>=r || i>j) {
            break;
        }
        swap(data,++i,j++);
    }
    swap(data,++i,r);
    return i;
}

template<class T>
int findOrderStatistic(T *data,int n,unsigned int k,int (*compare)(const T &a, const T &b)){
    unsigned int left = 0,right = n;
    while (true){
        unsigned int mid = partition(data,left,right,compare);
        if (mid==k){
            return data[mid];
        } else if (mid>k){
            right=mid;
        } else if (mid<k){
            left=mid+1;
        }
    }
}


Vector<int> scan(unsigned int &k,unsigned int &n){
    Vector<int> data(n);
    for (int i = 0;i<n;i++){
        std::cin>>data[i];
    }
    return data;
}

int main() {
    unsigned int n=0,k=0;
    std::cin>>n>>k;
    Vector<int> data=scan(k,n);
    std::cout << findOrderStatistic(data.begin(),data.size()-1,k,&compareInts) << std::endl;
    return 0;
}

//1 4 3 5
//
//1 5 3 4
//1 3 5 4

