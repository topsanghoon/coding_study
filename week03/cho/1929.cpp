#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N,M;
    cin>>N>>M;
    vector<bool>arr(M+1,true);
    arr[0]=false;
    arr[1]=false;
    for(int i=2; i*i<=M ; i++){
        if(arr[i]){
            for(int j=2; j*i<=M ; j++){
                arr[i*j]=false;
        }    
        }
        
    }

    for(int i=N;i<=M;i++){
        if(arr[i]){
            cout<<i<<'\n';
        }
    }
    
    return 0;
}