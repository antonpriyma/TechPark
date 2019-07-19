#include <iostream>
#include <set>
#include "JavaKeyWords.h"

using  namespace std;
int main() {
    JavaKeyWords keyWords;
    set<string> set1 =   keyWords.getKeyWordsSet();
    return 0;
}