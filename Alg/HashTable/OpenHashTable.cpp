//#include <iostream>
//#include <vector>
//#include <assert.h>
//
//#define DELETED false
//#define CONTAINS true
//
//const int DefaultTableSize = 8;
//const int MaxAlpha = 3;
//const int GrowFactor = 2;
//
//
//
//template <class T>
//struct HashTableNode{
//    T Data;
//    char flag{};
//
//    HashTableNode(const T &data,char flag){
//        Data=data;
//        this->flag=flag;
//    }
//
//    HashTableNode(){
//        flag=DELETED;
//    };
//
//};
//
//
//unsigned long Hash(const std::string &key, unsigned long tableSize){
//    unsigned long hash = 0;
//    for (char i : key) {
//        hash *= 31;
//        hash += i;
//        hash %= tableSize;
//    }
//    return hash;
//}
//
//unsigned long Hash2(const std::string &key, unsigned long tableSize){
//    //return (key * tableSize - 1) % tableSize;
//    unsigned long hash = (tableSize * key.size() + 1) % tableSize;
//    return hash;
//    //return 1;
//}
//
//
//
//template <class T>
//class HashTable{
//public:
//    HashTable();
//
//    bool Add(const T key);
//    bool Delete(const T key);
//    unsigned long getSize();
//    bool has(unsigned long hash, const T key);
//
//private:
//
//
//    bool growTable();
//    unsigned long getIndex(unsigned long prevIndex, unsigned long stepSize, unsigned long k);
//    std::vector<T> table;
//    std::vector<bool> flags;
//    int keysCount;
//    float fillingMetric;
//
//
//
//};
//
//template<class T>
//HashTable<T>::HashTable() {
//    keysCount = 0;
//    fillingMetric=0;
//    table.resize(DefaultTableSize);
//
//    flags.resize(DefaultTableSize,DELETED);
//}
//
////template<class T>
////HashTable<T>::~HashTable() {
////    for (int i = 0 ;i<table.size();i++){
////        HashTableNode<T>* node = table[i];
////        delete(node);
////    }
////
////
////}
//
//template<class T>
//bool HashTable<T>::has(unsigned long hash, const T key) {
//    unsigned long stepSize = Hash2(key, table.size());
//    unsigned long i =0;
//    while (flags[hash] != DELETED && i<table.size() ){
//        T data  = table[hash];
//        char flag = flags[hash];
//        if (data==key && flag==CONTAINS){
//            return true;
//        }
//        hash=getIndex(hash,stepSize,i++);
//    }
//    return false;
//}
//
//
//template<class T>
//bool HashTable<T>::Delete(const T key) {
//    unsigned long hash = Hash(key, table.size());
//    unsigned long stepSize = Hash2(key, table.size());
//    unsigned long i=0;
//    unsigned long buf = hash;
//    while (flags[hash]!= DELETED && i<table.size()){
//        T data  = table[hash];
//        char flag = flags[hash];
//        if (flag == CONTAINS && data== key){
//            flags[hash] = DELETED;
//            //table[i]->Data = NONE;
//            keysCount--;
//            fillingMetric=keysCount/float(table.size());
//            return true;
//        }
//        hash=getIndex(hash,stepSize,i++);
////        if (buf == hash)
////        {
////            break;
////        }
//    }
//
//    return false;
//
//
//}
//
//template<class T>
//bool HashTable<T>:: Add(const T key) {
//    unsigned long hash = Hash(key, table.size());
//    unsigned long stepSize = Hash2(key,table.size());
//
//    unsigned long i = 0;
//
//    while (flags[hash] == CONTAINS && i<table.size()){
//        T data  = table[hash];
//        char flag = flags[hash];
//        if (data==key && flag!=DELETED){
//            return false;
//        }
//        hash=getIndex(hash,stepSize,i++);
//    }
//
//    table[hash] = key;
//    flags[hash] = CONTAINS;
//    keysCount++;
//    fillingMetric=keysCount/float(table.size());
//    if (fillingMetric>=0.75){
//        growTable();
//    }
//    fillingMetric=keysCount/float(table.size());
//
//    return true;
//
//}
//
//template<class T>
//bool HashTable<T>::growTable() {
//    //vector<HashTableNode<T>*> newTable(table.size()*GrowFactor, nullptr);
//    //vector<HashTableNode<T>*> newTable = table;
//
//    table.resize(table.size()*GrowFactor);
//    flags.resize(flags.size()*GrowFactor,DELETED);
//    for (int i =0;i<table.size();i++){
//        T data  = table[i];
//        char flag = flags[i];
//
//            if (flag==CONTAINS) {
//                flags[i]=DELETED;
//                keysCount--;
//                Add(data);
//            }
//
//    }
//
//
//}
//
//template<class T>
//unsigned long HashTable<T>::getSize() {
//    return table.size();
//}
//
//template<class T>
//unsigned long HashTable<T>::getIndex(unsigned long prevIndex, unsigned long stepSize, unsigned long k) {
//    // return (prevIndex+k*stepSize)%table.size();
//    return (prevIndex+stepSize)%table.size();
//}
//
//int main() {
//    HashTable<std::string> table;
//    char command = 0;
//    std::string key;
//    while (std::cin>>command>>key){
//        switch (command){
//            case '+':
//                std::cout <<  (table.Add(key) ? "OK" : "FAIL") << std::endl;
//                break;
//            case '-':
//                std::cout <<  (table.Delete(key) ? "OK" : "FAIL") << std::endl;
//                break;
//            case '?':
//                std::cout <<  (table.has(Hash(key,table.getSize()),key) ? "OK" : "FAIL") << std::endl;
//                break;
//            default:
//                break;
//        }
//    }
//    return 0;
//}