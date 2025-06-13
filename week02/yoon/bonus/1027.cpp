#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];

    vector<vector<bool>> canSee(N, vector<bool>(N, false));

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            bool visible = true;
            for (int k = i + 1; k < j; ++k) {
                // Compare slope of (i,k) and (i,j)
                if ((ll)(H[k] - H[i]) * (j - i) >= (ll)(H[j] - H[i]) * (k - i)) {
                    visible = false;
                    break;
                }
            }
            if (visible) {
                canSee[i][j] = true;
                canSee[j][i] = true;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            if (i != j && canSee[i][j]) cnt++;
        }
        answer = max(answer, cnt);
    }

    cout << answer << '\n';
    return 0;
}
