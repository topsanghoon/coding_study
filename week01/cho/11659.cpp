#include <iostream>
using namespace std;
#include <vector>
int main() {
    
    int N,M;
    cin>>N>>M;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>arr=vector<int>(N);
    int s,e;
    int sum=0;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    for(int i=0;i<N;i++){
        sum+=arr[i];
        arr[i]=sum;
        // cout<<arr[i]<<' ';
    }

    for (int j=0; j<M; j++) {
        cin>>s>>e;
        cout<<arr[e-1]-arr[s-2]<<'\n';
    }
    
    return 0;
}