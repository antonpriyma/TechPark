#include <iostream>
#include <vector>
#include <assert.h>

#define DELETED 0
#define CONTAINS 1
#define NONE -1

const int DefaultTableSize = 8;
const int MaxAlpha = 3;
const int GrowFactor = 2;

using namespace std;

template <class T>
struct HashTableNode{
    T Data;
    char flag{};

    HashTableNode(const T &data,char flag){
        Data=data;
        this->flag=flag;
    }

    HashTableNode(){
        flag=NONE;
    };

};


unsigned long Hash(const string &key, unsigned long tableSize){
    unsigned long hash = 0;
    for (char i : key) {
        hash *= 31;
        hash += i;
        hash %= tableSize;
    }
    return hash;
}

unsigned long Hash2(const string &key, unsigned long tableSize){
    //return (key * tableSize - 1) % tableSize;
    unsigned long hash = (tableSize * key.size() + 1) % tableSize;
    return hash;
    //return 1;
}



template <class T>
class HashTable{
public:
    HashTable();



    bool Add(const T& key);
    bool Delete(const T& key);
    unsigned long getSize();
    bool has(unsigned long hash, const T& key);

private:


    bool growTable();
    unsigned long getIndex(unsigned long prevIndex, unsigned long stepSize, unsigned long k);
    vector<HashTableNode<T>> table;
    int keysCount;
    float fillingMetric;



};

template<class T>
HashTable<T>::HashTable() {
    keysCount = 0;
    fillingMetric=0;
    table.resize(DefaultTableSize);
}

//template<class T>
//HashTable<T>::~HashTable() {
//    for (int i = 0 ;i<table.size();i++){
//        HashTableNode<T> node = table[i];
//        delete(node);
//    }
//
//
//}

template<class T>
bool HashTable<T>::has(unsigned long hash, const T &key) {
    unsigned long stepSize = Hash2(key, table.size());
    unsigned long i =0;
    while (table[hash].flag!=NONE && i<table.size() ){
        HashTableNode<T> node = table[hash];
        if (node.Data==key && node.flag==CONTAINS){
            return true;
        }
        hash=getIndex(hash,stepSize,i++);
    }
    return false;
}


template<class T>
bool HashTable<T>::Delete(const T &key) {
    unsigned long hash = Hash(key, table.size());
    unsigned long stepSize = Hash2(key, table.size());
    unsigned long i=0;
    unsigned long buf = hash;
    while (table[hash].flag !=NONE && i<table.size()){
        HashTableNode<T> node = table[hash];
        if (node.flag == CONTAINS && node.Data== key){
            table[hash].flag = DELETED;
            keysCount--;
            fillingMetric=keysCount/float(table.size());
            return true;
        }
        hash=getIndex(hash,stepSize,i++);

    }

    return false;


}

template<class T>
bool HashTable<T>:: Add(const T &key) {
    unsigned long hash = Hash(key, table.size());
    unsigned long stepSize = Hash2(key,table.size());

    unsigned long i = 0;
    while ( table[hash].flag == CONTAINS && i<table.size()){
        const HashTableNode<T>& node = table[hash];
        if (node.Data==key){
            return false;
        }
        hash=getIndex(hash,stepSize,i++);
    }

    table[hash].Data = key;
    table[hash].flag = CONTAINS;
    keysCount++;
    fillingMetric=keysCount/float(table.size());
    if (fillingMetric>=0.75){
        growTable();
    }
    fillingMetric=keysCount/float(table.size());

    return true;

}

template<class T>
bool HashTable<T>::growTable() {

    table.resize(table.size()*GrowFactor);
    for (int i =0;i<table.size();i++){
        HashTableNode<T> node = table[i];
        if (node.flag != NONE){
            table[i].flag = NONE;
            if (node.flag==CONTAINS) {
                keysCount--;
                Add(node.Data);
            }
        }
    }


}

template<class T>
unsigned long HashTable<T>::getSize() {
    return table.size();
}

template<class T>
unsigned long HashTable<T>::getIndex(unsigned long prevIndex, unsigned long stepSize, unsigned long k) {
    // return (prevIndex+k*stepSize)%table.size();
    return (prevIndex+stepSize)%table.size();
}

int main() {
    HashTable<string> table;
    char command = 0;
    string key;
    while (cin>>command>>key){
        switch (command){
            case '+':
                cout <<  (table.Add(key) ? "OK" : "FAIL") << endl;
                break;
            case '-':
                cout <<  (table.Delete(key) ? "OK" : "FAIL") << endl;
                break;
            case '?':
                cout <<  (table.has(Hash(key,table.getSize()),key) ? "OK" : "FAIL") << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}