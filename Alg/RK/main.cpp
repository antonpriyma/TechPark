#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    int a[15];
    for (int i =0;i<15;i++){
        a[i]=i+1;
    }
    for (int i =0;i<15;i++){
        int temp = a[i];
        a[i]=a[i/2];
        a[i/2]=temp;
    }

    for(int i =0;i<15;i++){
        std::cout<<a[i]<<" ";
    }
    return 0;
}