#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>


/*
메모리 2020kb  시간 0ms
*/
int main() {
    int N;
    cin>>N;
    int temp;
    vector<int> dp(N+1,0);
    dp.push_back(0);
    vector<int> arr(N+1,0);
    arr.push_back(0);
    for (int i=1; i<=N; i++) {
        cin>>temp;
        arr[i] = temp;
        if(i==1) dp[i] = arr[i];
        if(i==2) dp[i]=max(dp[i-1]+arr[i] , arr[i]);
        if(i>=3) dp[i] = max(dp[i-2]+arr[i] , dp[i-3]+arr[i-1]+arr[i]);        
    }

    cout<<dp[N];
    
    return 0;
}