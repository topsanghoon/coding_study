#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/13398
// 연속합2
vector<int> arr;
int main(void){
    int N;
    cin >> N;
    int temp;
    for(int i = 0; i < N; i++){
        cin >> temp;
        arr.push_back(temp);
    }
 
    vector<int> dp1(N);
    vector<int> dp2(N);
    dp1[0] = arr[0];
    for(int i = 1; i < N; i++){
        dp1[i] = max(arr[i],dp1[i-1]+arr[i]);
    }

    dp2[N-1] = arr[N-1];
    for(int i = N-2; i > 0; i--){
        dp2[i] = max(arr[i], dp2[i+1]+arr[i]);
    }

    int result = *max_element(dp1.begin(),dp1.end());
    for(int i = 1; i < N-1; i++){
        result = max(result, dp1[i-1]+dp2[i+1]);
    }

    // for(int i = 0; i < N; i++){
    //     cout << dp1[i] << " ";
    // }
    // cout << "\n";
    // for(int i = 0; i < N; i++){
    //     cout << dp2[i] << " ";
    // }
    //cout << "\n";
    cout << result;
}