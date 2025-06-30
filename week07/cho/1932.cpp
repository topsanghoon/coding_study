#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> tri;
    vector<vector<int>> dp(N);

    for (int i = 0; i < N; i++) {
        dp[i] = vector<int>(i + 1, 0);
    }
    for (int i = 0; i < N; i++) {
        vector<int> row;
        for (int j = 0; j <= i; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        tri.push_back(row);
    }
    
    dp[0][0] = tri[0][0]; 
    for (int i = 1; i < N; i++) { 
        for (int j = 0; j <= i; j++) {
            if (j == 0) { 
                dp[i][j] = dp[i - 1][j] + tri[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
            } else { 
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
            }
        }
    }

    
    int ans = *max_element(dp[N - 1].begin(), dp[N - 1].end());
    cout << ans << endl;

    return 0;
}
