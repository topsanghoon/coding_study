#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> stairs(n + 1, 0);  // 1부터 n까지
    vector<int> DP(n + 1, 0);      // 최대 점수 저장

    for (int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }

    // 예외 처리
    if (n == 1) {
        cout << stairs[1] << "\n";
        return 0;
    }

    // 초기값 설정
    DP[1] = stairs[1];
    DP[2] = stairs[1] + stairs[2];

    for (int i = 3; i <= n; i++) {
        DP[i] = max(DP[i - 2], DP[i - 3] + stairs[i - 1]) + stairs[i];  //두칸을 뛰어 넘어온 것과, 이전 칸을 밟았고, 
    }                                                                   //그전에 두칸을 뛰어 넘어온 경우 중 최대값 사용

    cout << DP[n] << "\n";

    return 0;
}
