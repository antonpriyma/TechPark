#include <iostream>

using namespace std;

int countWay(int arrive, int depart, int *sheldure, size_t n){
    int timeMin=1000000000,minJ=0;
    for(int j=0;j<n;j++){
        if (sheldure[j]<arrive){
            if (arrive-sheldure[j]<timeMin){
                timeMin=arrive-sheldure[j];
                minJ=j;
            }
            if (sheldure[j]==0){
                break;
            }
        }
    }
    sheldure[minJ]=depart;
    return minJ;
}

int main() {
    size_t n=0;
    int depart=0,arrive=0,max=-1;
    cin>>n;
    auto *sheldure = new int[n];
    for (int i=0;i<n;i++){
        cin>>arrive>>depart;
        int buf=countWay(arrive,depart,sheldure,n);
        if (buf>max){
            max=buf;
        }
    }

    cout<<max+1;
    delete[](sheldure);


    return 0;
}