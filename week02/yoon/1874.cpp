//13:31 13:55
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> list(n);
    for (int i = 0; i < n; ++i) {
        cin >> list[i];
    }

    stack<int> st;
    vector<char> result;
    int current = 1;
    bool possible = true;

    for (int num : list) {
        while (current <= num) {
            st.push(current++);
            result.push_back('+');
        }

        if (!st.empty() && st.top() == num) {
            st.pop();
            result.push_back('-');
        } else {
            // 불가능한 수열
            possible = false;
            break;
        }
    }

    if (possible) {
        for (char op : result)
            cout << op << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}