//못품
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, S;
    int64 a, b;
    if (!(cin >> R >> S >> a >> b)) return 0;

    // 입력
    vector<vector<int64>> grid(R, vector<int64>(S));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < S; ++j) cin >> grid[i][j];
    }

    // a,b 정규화
    int64 L = min(a, b), Rg = max(a, b);
    int64 base = Rg - L; // |a-b|

    // 전치해서 H = min(R,S), W = max(R,S) 구조로 맞춤 (복잡도 최적화)
    int H = R, W = S;
    if (R > S) {
        vector<vector<int64>> t(S, vector<int64>(R));
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < S; ++j)
                t[j][i] = grid[i][j];
        grid.swap(t);
        H = S; W = R;
    }

    // 답을 위한 delta = [L,R] 까지의 최소 거리
    const int64 INF = (1LL<<62);
    int64 bestDelta = INF;

    // 두 행(top,bottom)을 고정하여 1D 열 배열로 축소
    vector<int64> colSum(W);
    for (int top = 0; top < H; ++top) {
        fill(colSum.begin(), colSum.end(), 0LL);
        for (int bottom = top; bottom < H; ++bottom) {
            // 열별 누적합 업데이트
            for (int k = 0; k < W; ++k) colSum[k] += grid[bottom][k];

            // 1D 양수 배열에서 [L,Rg]에 가장 가까운 연속 부분합 찾기 (슬라이딩 윈도우)
            int l = 0;
            int64 sum = 0;
            for (int r = 0; r < W; ++r) {
                sum += colSum[r];
                // Rg 초과하는 동안, 초과분 후보 갱신하며 l 이동
                while (sum > Rg && l <= r) {
                    bestDelta = min(bestDelta, sum - Rg);
                    sum -= colSum[l++];
                }
                // 이제 sum <= Rg
                if (sum >= L) {
                    // [L,Rg] 구간 내 ⇒ 정답은 |a-b|
                    cout << base << '\n';
                    return 0;
                } else {
                    // sum < L ⇒ 아래쪽 모자람 후보
                    bestDelta = min(bestDelta, L - sum);
                }
            }
        }
    }

    // 구간 내 합이 한 번도 없었다면
    // 최솟값 = |a-b| + 2 * delta
    // (f(C)=|C-a|+|C-b| = |a-b| + 2*dist(C, [L,R]))
    if (bestDelta == INF) {
        // 이론상 도달 불가(적어도 하나의 직사각형 존재)하지만 안전차원
        cout << base << '\n';
    } else {
        cout << base + 2 * bestDelta << '\n';
    }
    return 0;
}