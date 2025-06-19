#include <iostream>
#include <vector>
using namespace std;
int main() {
    long long N,M;
    int res=0;
    cin>>N>>M;
    vector<bool>arr(M+1,true);
    vector<bool>arr_res(M+1,false);
    arr[0]=arr[1]=false;
    for (int i=2;i*i<=M ;i++ ) {
        if(arr[i]){
            for(int j=2;i*j<=M;j++){
                arr[i*j]=false;
            }
        }
    }

    for(long long i=2; i<=M ; i++){
        if(arr[i]){
            long long tmp=i*i;
            while(tmp<=M){
                arr_res[tmp]=true;
                tmp=tmp*i;
            }
        }    
    } 
    
    

    
    for (int i=N;i<=M ; i++) {
        if(arr_res[i]){
            cout<<i<<'\n';
            res+=1;
        }
    }
    cout<<res;
    return 0;
}
