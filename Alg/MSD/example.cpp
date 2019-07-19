//
//#include <iostream>
//#include <stack>
//#include <cstdlib>
//#include <ctime>
//typedef unsigned long item;
//#define bitsword 16
//#define exch(A, B) { item t = A; A = B; B = t; }
//using namespace std;
//
//int digit(long a, int d)
//{
//    stack<int> stck;
//
//    int *BinaryArray = new int[15];
//    int i = 0;
//    /*converts decimal to binary*/
//    while(i < 15)
//    {
//        if( a > 0)
//        {
//            stck.push(a % 2);
//            a = a / 2;
//            i++;
//        }
//        else
//        {
//            stck.push(0);
//            i++;
//        }
//    }
//    i = 0;
//    /*Stores the binary representation in correct order*/
//    while(!stck.empty())
//    {
//        BinaryArray[i] = stck.top();
//        stck.pop();
//        i++;
//    }
//    /*returns the bit specified by "d"*/
//    return BinaryArray[d];
//}
//
//
///*Binary quicksort function*/
//void QuicksortB(item a[], int l, int r, int d)
//{
//
//    int i= l, j = r;
//    if (r <= l || d > bitsword) return;
//    while (j != i)
//    {
//        while (digit(a[i], d) == 0 && (i < j)) i++;
//        while (digit(a[j], d) == 1 && (j > i)) j--;
//        exch(a[i], a[j]);
//    }
//    if (digit(a[r], d) == 0) j++;
//    QuicksortB(a, j, r, d+1);
//    QuicksortB(a, l, j-1, d+1);
//
//
//}
//
//void sort(item a[], int l, int r)
//{
//    QuicksortB(a, l, r, 0);
//    /*outputs the sorted array*/
//    int i = 0;
//    while(i < r+1)
//    {
//        cout<<a[i]<<endl;
//        i++;
//    }
//}
//
///*test program*/
//int main()
//{
//    /* array of random values */
//    int MAX = 32767;
//    unsigned long *TestArray = new unsigned long[MAX];
//    /*variable initialization*/
//    unsigned long a, b;
//    a = 0;
//    b = 3;
//    srand(time(0));   /*initialize seed "randomly"*/
//    /*initialize array with random values*/
//    cout<<"Loading array wait..."<<endl;
//    /*outputs the unsorted array*/
//    for(int i=0; i < b; i++)
//    {
//        cin>>TestArray[i];
//        cout<<TestArray[i]<<endl;
//    }
//    cout<<"sorting..."<<endl;
//    /* sort data */
//    sort(TestArray, a, b-1);
//    /*deallocate array space */
//    delete [] TestArray;
//    return 0;
//}