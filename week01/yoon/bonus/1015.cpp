#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // (값, 원래 인덱스) 저장
    vector<pair<int, int>> with_index;
    for (int i = 0; i < n; i++) {
        with_index.push_back({A[i], i});
    }

    // 값 기준 오름차순 정렬 (값이 같을 때 인덱스 오름차순 → 사전순 보장)
    sort(with_index.begin(), with_index.end());

    // 정답 P 생성
    vector<int> P(n);
    for (int new_pos = 0; new_pos < n; new_pos++) {
        int original_index = with_index[new_pos].second;
        P[original_index] = new_pos;
    }

    // 출력
    for (int i = 0; i < n; i++) {
        cout << P[i] << " ";
    }

    return 0;
}
