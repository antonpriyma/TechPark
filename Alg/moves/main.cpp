#include <iostream>
#include <vector>




using namespace std;

//void shift(int &src,const int N){
//    if (src>N-1){
//        src-=N;
//        return;
//    }
//}
void move(const int N,const int K,vector<int> &list,int &size,int &count){

    for (int i=0;i<K;i++){
        int j=1;
        if (count>=N-1){
            count-=N;
        }
        int buf=count+j;
        while (list[buf]==-1){
            j++;
            buf = count+j;
            if (buf>=N){
                buf-=N;
            }
        }
        count=buf;
    }
    list[count]=-1;
    size--;
}

vector<int> init(int &K,int &N,int &size){
    cin>>N>>K;
    vector<int> list(N);
    for (int i =0;i<N;i++){
        list[i]=i;
    }
    size=N;
    return list;

}



int main() {
    int N=0,K=0,size=0,count=-1;
    vector<int> list =  init(K,N,size);

    while (size>=2){
        move(N,K,list,size,count);
    }
    for(int i:list){
        if (i!=-1){
            cout<<i+1;
            return 0;
        }
    }
    return 0;
}