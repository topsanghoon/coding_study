#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    stack<int> stack_temp;
    vector<char> result;
    int j = 0;
    int i = 1;

    while (i <= N || !stack_temp.empty()) {
        if (!stack_temp.empty() && stack_temp.top() == arr[j]) {
            stack_temp.pop();
            result.push_back('-');
            j++;
            if (j >= N) break; // 배열 범위 보호
        } else {
            if (i > N) break; // 더 이상 푸시 불가능
            stack_temp.push(i);
            result.push_back('+');
            i++;
        }
    }

    // 모든 요소 처리 여부 확인
    if (j == N) {
        for (char c : result) {
            cout << c << '\n';
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}
