#include <iostream>

using namespace std;

int factorial(int x){
    int result = 1;
    for (int i = 1;i<=x;i++){
        result*=i;
    }
    return result;
}

int main()
{
    int x;
    cout << "Введите x: ";
    cin >> x;
    cout << "x! = "<<factorial(x);
    return 0;
}