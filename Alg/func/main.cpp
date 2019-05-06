#include <iostream>

using namespace std;

void pow(int x,int p){
    for (int i = 0;i<p;i++){
        x=x*x;
    }
    return x;
}
int main()
{
    int x=0,y=0,z=0;
    cin>>x;
    int result=pow(x,3);
    cout<<result<<endl;
    cin>>y;
    result = pow(y,3);
    cout<<result<<endl;
    cin>>z;
    result = pow(z,3);
    cout<<result<<endl;

    return 0;
}