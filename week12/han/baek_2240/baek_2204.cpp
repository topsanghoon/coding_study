#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 자두나무
// https://www.acmicpc.net/problem/2240

// int dp[1000+1][30+1] = {0,};
// int T, W;
// vector<int> arr;

// int main(void){
//     cin >> T >> W;
//     arr.push_back(0);
//     for(int i = 0; i < T; i++){
//         int temp;
//         cin >> temp;
//         arr.push_back(temp);
//     }

//     for(int i = 1; i <= T; i++){
//         for(int j = 0; j <= W; j++){
//             if( j == 0) dp[i][j] = dp[i-1][j];
//             else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]); 
//             if(arr[i] == 1 && j % 2 == 0){
//                 dp[i][j] += 1;
//             }
//             else if(arr[i] == 2 && j % 2 == 1){
//                 dp[i][j] += 1;
//             }
//         }
//     }

//     // for(int i = 1; i <= T; i++){
//     //     for(int j = 0; j <= W; j++){
//     //         cout << dp[i][j] << " ";
//     //     }
//     //     cout << "\n";
//     // }

//     int answer = 0;
//     for(int i = 0; i <= W; i++){
//         if(answer < dp[T][i]) answer = dp[T][i];
//     }
//     cout << answer;
// }

int T, W;
int dp[1000+1];
vector<int> arr;

int main(void){
    cin >> T >> W;
    arr.push_back(0);
    for(int i = 0; i < T; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for(int i = 1; i <= T; i++){
        for(int j = 0; j <= W; j++){
            if(j > 0) dp[j] = max(dp[j], dp[j-1]);
            
            if((arr[i] == 1 && j % 2 == 0) || (arr[i] == 2 && j % 2 == 1)) dp[j] += 1;
        }
    }

    int answer = 0;
    for(int i = 0; i <= T; i++){
        if(answer < dp[i]) answer = dp[i];
    }
    cout << answer;
}