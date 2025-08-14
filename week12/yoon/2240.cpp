#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

    int T, W;
    cin >> T >> W;

    vector<vector<int>> jadus(2, vector<int>(T+1, 0));
    for(int i = 1; i <= T; i++){
        int temp;
        cin >> temp;
        jadus[temp == 1 ? 0 : 1][i] = 1;
    }

    vector<vector<vector<int>>> jadus_dp (W+1, vector<vector<int>>(T+1, vector<int> (2, 0)));
    for(int i = 1; i <= T; i++){ // 회차
        jadus_dp[0][i][0] = jadus_dp[0][i-1][0] + jadus[0][i];
    }

    for(int i = 1; i <= T; i++){ // 회차
        for(int j = 1; j <= W; j++){ // 움직인 수

            jadus_dp[j][i][0] = max(jadus_dp[j][i - 1][0] + jadus[0][i], jadus_dp[j - 1][i - 1][1] + jadus[0][i]);
            jadus_dp[j][i][1] = max(jadus_dp[j][i - 1][1] + jadus[1][i], jadus_dp[j - 1][i - 1][0] + jadus[1][i]);
        }
    }

    int answer = 0;
    for(int i = 0; i <= W; i++){
        answer = max(answer, jadus_dp[i][T][0]);
        answer = max(answer, jadus_dp[i][T][1]);
    }

    cout << answer;

    // for(int i = 0; i <= W; i++){
    //     for(int j = 0; j <= T; j++){
    //         cout << jadus_dp[i][j][0] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "\n\n";
    // for(int i = 0; i <= W; i++){
    //     for(int j = 0; j <= T; j++){
    //         cout << jadus_dp[i][j][1] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}