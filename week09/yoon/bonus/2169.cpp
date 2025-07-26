#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    vector<vector<int>> DP(n, vector<int>(m));
    DP[0][0] = map[0][0];

    for (int j = 1; j < m; j++)
        DP[0][j] = DP[0][j - 1] + map[0][j];

    for (int i = 1; i < n; i++) {
        vector<int> left(m), right(m);

        // 왼 → 오
        left[0] = DP[i - 1][0] + map[i][0];
        for (int j = 1; j < m; j++)
            left[j] = max(left[j - 1], DP[i - 1][j]) + map[i][j];

        // 오 → 왼
        right[m - 1] = DP[i - 1][m - 1] + map[i][m - 1];
        for (int j = m - 2; j >= 0; j--)
            right[j] = max(right[j + 1], DP[i - 1][j]) + map[i][j];

        // 둘 중 큰 값을 DP에 저장
        for (int j = 0; j < m; j++)
            DP[i][j] = max(left[j], right[j]);
    }

    cout << DP[n - 1][m - 1];
    return 0;
}
