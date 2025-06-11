#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    long long result = 0;
    stack<int> st;
    int h;

    for (int i = 0; i < N; ++i) {
        cin >> h;

        // 스택에서 현재 빌딩보다 작거나 같은 빌딩은 제거
        while (!st.empty() && st.top() <= h) {
            st.pop();
        }

        // 남아있는 스택에 있는 빌딩 수가 현재 빌딩에서 볼 수 있는 옥상 수
        result += st.size();

        // 현재 빌딩 추가
        st.push(h);
    }

    cout << result << '\n';
    return 0;
}
