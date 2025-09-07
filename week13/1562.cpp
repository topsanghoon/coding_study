#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000000;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;

    vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(10, vector<long long>(1 << 10, 0)));

    for(int i = 1; i < 10; i++){
        dp[1][i][1 << i] = 1;
    }

    for (int len = 1; len < N; len++) {
        int cur = len % 2;
        int next = (len + 1) % 2;
        for (int j = 0; j < 10; j++) {
            fill(dp[next][j].begin(), dp[next][j].end(), 0);
        }

        for (int last = 0; last <= 9; last++) {
            for (int mask = 0; mask < (1<<10); mask++) {
                long long val = dp[cur][last][mask];
                if (!val) continue;

                if (last > 0) {
                    int nm = mask | (1<<(last-1));
                    dp[next][last-1][nm] = (dp[next][last-1][nm] + val) % MOD;
                }

                if (last < 9) {
                    int nm = mask | (1<<(last+1));
                    dp[next][last+1][nm] = (dp[next][last+1][nm] + val) % MOD;
                }
            }
        }
    }

    long long ans = 0;
    int final_mask = (1<<10) - 1;
    for (int d = 0; d <= 9; d++) {
        ans = (ans + dp[N%2][d][final_mask]) % MOD;
    }

    cout << ans << "\n";
    return 0;

    return 0;
}