#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int R, S;
    long long a, b;
    cin >> R >> S >> a >> b;

    long long low = min(a,b), high = max(a,b);
    long long answer = LLONG_MAX;

    // 입력을 prefix sum (행별 누적합)으로 준비
    vector<vector<long long>> price(R, vector<long long>(S+1, 0));
    for (int i = 0; i < R; i++) {
        for (int j = 1; j <= S; j++) {
            int temp; cin >> temp;
            price[i][j] = price[i][j-1] + temp;
        }
    }

    // 열 구간 [i, j]
    for (int i = 1; i <= S; i++) {
        for (int j = i; j <= S; j++) {

            // rowSum[r] = (r행, i~j 합)
            vector<long long> rowSum(R);
            for (int r = 0; r < R; r++) {
                rowSum[r] = price[r][j] - price[r][i-1];
            }

            // prefix sum 준비
            vector<long long> pref(R+1, 0);
            for (int r = 0; r < R; r++) {
                pref[r+1] = pref[r] + rowSum[r];
            }

            // multiset 대신 vector 정렬로도 가능
            // 여기서는 running lower_bound 쓰기 위해 set 사용
            multiset<long long> seen;
            seen.insert(0); // pref[0]

            for (int r = 1; r <= R; r++) {
                long long cur = pref[r];

                // target = 중간값 근처를 찾아야 함
                long long target = (a+b)/2;

                // 우리는 cur - prev 가 subSum
                // 즉 prev ≈ cur - target인 값을 찾아야 함
                long long need = cur - target;

                auto it = seen.lower_bound(need);
                if (it != seen.end()) {
                    long long subSum = cur - *it;
                    long long cost;
                    if (subSum < low) cost = (a+b) - 2*subSum;
                    else if (subSum > high) cost = 2*subSum - (a+b);
                    else cost = high - low;
                    answer = min(answer, cost);
                }
                if (it != seen.begin()) {
                    --it;
                    long long subSum = cur - *it;
                    long long cost;
                    if (subSum < low) cost = (a+b) - 2*subSum;
                    else if (subSum > high) cost = 2*subSum - (a+b);
                    else cost = high - low;
                    answer = min(answer, cost);
                }

                seen.insert(cur);
            }
        }
    }

    cout << answer << "\n";
    return 0;
}