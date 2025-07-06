#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

// 현재 max_sum 이하로 나누었을 때 몇 개의 블록이 필요한지 계산
int count_partition(const vector<ll>& arr, ll max_sum) {
    ll current_sum = 0;
    int block_count = 1;  // 최소 한 구간은 필요
    for (ll num : arr) {
        if (current_sum + num > max_sum) {
            block_count++;
            current_sum = num;
        } else {
            current_sum += num;
        }
    }
    return block_count;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<ll> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    ll low = *max_element(arr.begin(), arr.end());             // 가장 큰 값은 반드시 포함되어야 하므로 최소
    ll high = accumulate(arr.begin(), arr.end(), 0LL);         // 모든 합
    ll answer = high;

    while (low <= high) {
        ll mid = (low + high) / 2;
        int blocks = count_partition(arr, mid);

        if (blocks <= M) {
            answer = mid;
            high = mid - 1; // 더 작게 나눌 수 있는지 시도
        } else {
            low = mid + 1;  // 너무 많이 나뉨 -> 크기 늘리기
        }
    }

    cout << answer << "\n";
    return 0;
}
