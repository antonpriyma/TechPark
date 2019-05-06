#include <iostream>
#include <assert.h>

#define INF 1000000001


//На вокзале есть некоторое количество тупиков, куда прибывают электрички.
//Этот вокзал является их конечной станцией.
//Дано расписание движения электричек, в котором для каждой электрички указано время ее прибытия, а также время отправления в следующий рейс.
//Электрички в расписании упорядочены по времени прибытия. Когда электричка прибывает, ее ставят в свободный тупик с минимальным номером.
//При этом если электричка из какого-то тупика отправилась в момент времени X, то электричку, которая прибывает в момент времени X, в этот тупик ставить нельзя, а электричку, прибывающую в момент X+1 — можно.
//В данный момент на вокзале достаточное количество тупиков для работы по расписанию.
//Напишите программу, которая по данному расписанию определяет, какое минимальное количество тупиков требуется для работы вокзала.




class Pair {
public:
    int getA() { return this->a; }
    int getB() { return this->b; }
    Pair(int a, int b);
    Pair();

private:
    int a;
    int b;
};
Pair::Pair(int a, int b) {
    this->a = a;
    this->b = b;
}
Pair::Pair() {}
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
    assert(size>=0);
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

template <class T> void Vector<T>::push_back(const T &value) {
    if (my_size >= my_capacity)
        reserve(my_capacity + 5);
    buffer[my_size++] = value;
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

class Heap {
public:
    Heap();
    Heap(int n);
    ~Heap();
    void insert(int val);
    void swap(int a, int b);
    int max(int a, int b);
    int deleteMin();
    int getMaxSize();
    int genMin() {
        if (heap.size() > 0)
            return heap[0];
        return -1;
    };
    int size() { return heap.size(); }

private:
    int left(int parent);
    int right(int parent);
    int parent(int child);
    void heapifyUp(int index);
    void heapifyDown(int index);
    void checkMax();
    void deleteElement(int index);

private:
    int maxSize;
    Vector<int> heap;
};

Heap::Heap() { maxSize = 0; }

Heap::Heap(int n) {
    assert(n>=0);
    maxSize = 0;
    heap = Vector<int>(n);
}

Heap::~Heap() {}

void Heap::insert(int val) {
    heap.push_back(val);
    heapifyUp(heap.size() - 1);
}

int Heap::deleteMin() {
    int min = heap.front();
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapifyDown(0);
    return min;
}

void Heap::heapifyUp(int index) {
    while ((index > 0) && (parent(index) >= 0) &&
           (heap[parent(index)] > heap[index])) {
        int tmp = heap[parent(index)];
        heap[parent(index)] = heap[index];
        heap[index] = tmp;
        index = parent(index);
    }
}

void Heap::heapifyDown(int index) {
    assert(index>0);
    int leftChild;
    int rightChild;
    int largestChild;

    for (;;) {
        leftChild = left(index);
        rightChild = right(index);
        largestChild = index;

        if (leftChild > 0 && heap[leftChild] < heap[largestChild]) {
            largestChild = leftChild;
        }

        if (rightChild > 0 && heap[rightChild] < heap[largestChild]) {
            largestChild = rightChild;
        }

        if (largestChild == index) {
            break;
        }

        int temp = heap[index];
        heap[index] = heap[largestChild];
        heap[largestChild] = temp;
        index = largestChild;
    }
};

int Heap::left(int parent) {
    int i = (parent << 1) + 1; // 2 * parent + 1
    return (i < heap.size()) ? i : -1;
}

int Heap::right(int parent) {
    int i = (parent << 1) + 2; // 2 * parent + 2
    return (i < heap.size()) ? i : -1;
}

int Heap::parent(int child) {
    if (child != 0) {
        int i = (child - 1) >> 1;
        return i;
    }
    return -1;
}

void Heap::swap(int a, int b) {
    int tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;
}

int Heap::max(int a, int b) {
    if (heap[a] > heap[b]) {
        return a;
    }
    return b;
}

void Heap::deleteElement(int index) {
    heap[index] = INF;
    heapifyDown(index);
    heap.pop_back();
}

void Heap::checkMax() {
    if (heap.size() > maxSize) {
        maxSize = heap.size();
    }
}

int Heap::getMaxSize() { return maxSize; }

class PriorityQuene {
public:
    int size() { return heap.size(); };
    int top() { return heap.genMin(); };
    void push(int val) { heap.insert(val); };
    int pop() { heap.deleteMin(); };


private:
    Heap heap;
};



int calculateTrains(Vector<Pair> &sheldure) {
    int max = 0;
    auto *heap = new PriorityQuene();
    for (auto &i : sheldure) {
        int arrive = i.getA();
        int depart = i.getB();
        if (heap->size() <= 0) {
            heap->push(depart);
            if (heap->size() > max) {
                max = heap->size();
            }
            continue;
        }
        if (arrive <= heap->top()) {
            heap->push(depart);
            if (heap->size() > max) {
                max = heap->size();
            }

        } else {
            while (heap->size() > 0 && arrive > heap->top()) {
                heap->pop();
            }
            heap->push(depart);
            if (heap->size() > max) {
                max = heap->size();
            }
        }
    }
    delete (heap);
    return max;
}

int main() {
    unsigned int n = 0;

    int depart = 0, arrive = 0;
    std::cin>>n;
    Vector<Pair> sheldure(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arrive >> depart;
        sheldure[i] = Pair(arrive, depart);
    }

    std::cout << calculateTrains(sheldure);
    return 0;
}
