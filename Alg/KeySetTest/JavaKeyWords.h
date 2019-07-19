//
// Created by anton on 29.03.19.
//

#ifndef KEYSETTEST_JAVAKEYWORDS_H
#define KEYSETTEST_JAVAKEYWORDS_H

#include <iostream>
#include <fstream>
#include <set>

#endif //KEYSETTEST_JAVAKEYWORDS_H
using namespace std;
class JavaKeyWords{
private:

public:
    set<string> keyWordsSet;
    JavaKeyWords(){
        ifstream myfile("JavaKeyWords.txt");;
        string key;

        if (myfile.is_open()) {
            while (getline(myfile, key)) {
                keyWordsSet.insert(key);
            }
            myfile.close();
        }
    }

    const set<string> &getKeyWordsSet() const;


};

const set<string> &JavaKeyWords::getKeyWordsSet() const {
    return keyWordsSet;
}

for (program p: v){
    check(p1,p)
}
