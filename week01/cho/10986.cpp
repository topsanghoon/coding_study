#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int sum=0;
    int count=0;
    int result=0;
    vector<int>arr = vector<int>(N);
    
    for (int i=0; i<N; i++) {
        cin>>arr[i];
        sum+=arr[i];
        if(sum%M==0){
            sum=0;
            count++;
        }
            
    }
    result=(1<<count)-1;
    cout<<result;
    

    
    
    

    return 0;
}