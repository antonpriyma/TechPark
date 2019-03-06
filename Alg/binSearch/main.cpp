#include <iostream>
#include <vector>

using namespace std;

void scan(vector<int> &a,vector<int> &b,int n ,int m){
    for (int i =0;i<n;i++){
        cin>>a[i];
    }
    getchar();
    for (int i =0;i<m;i++){
        cin>>b[i];
    }
}

int binsearch(vector<int> array,int key,int size){
    int start = 0,end = size,mid=0;
    int ans = size+1;
    while (start <= end){
        mid = start + (end-start)/2;
        if (array[start] == key)
            return start;


        if (array[mid]>=key){
            ans=mid;
            end=mid-1;
        } else {
            start=mid+1;
        }
    }
    return ans;
}

int main() {
    unsigned long n=0,m=0;
    cin>>n>>m;
    vector<int> a(n),b(m);
    scan(a,b,n,m);
    for(int i =0;i<m;i++){
        cout<<binsearch(a,b[i],n-1)<<" ";
    }
    return 0;
}