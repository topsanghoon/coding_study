#include <iostream>
#include <cmath>

using namespace std;

bool is_black(int s, int N, int K, int r, int c) {
    if (s == 0) return false;

    int len = pow(N, s - 1);         // 현재 블록 한 칸 크기
    int nr = r / len;                // 상위 블록에서 몇 번째 row
    int nc = c / len;                // 상위 블록에서 몇 번째 col

    // 중앙 블록인지 판별
    int border = (N - K) / 2;
    if (border <= nr && nr < border + K &&
        border <= nc && nc < border + K)
        return true;

    // 아니면 더 작은 블록에서 재귀 탐색
    return is_black(s - 1, N, K, r % len, c % len);
}



int main(){

    int s, N, K, R1, R2, C1, C2;
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

    for(int i = R1; i <= R2; i++){
        for(int j = C1; j <= C2; j++){
            cout << (is_black(s, N, K, i, j) ? "1" : "0");
        }
        cout << "\n";
    }

    return 0;
}