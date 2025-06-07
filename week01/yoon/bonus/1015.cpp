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

    vector<pair<int, int>> with_index;
    for (int i = 0; i < n; i++) {
        with_index.push_back({A[i], i});
    }

    sort(with_index.begin(), with_index.end());

    vector<int> P(n);
    for (int new_pos = 0; new_pos < n; new_pos++) {
        int original_index = with_index[new_pos].second;
        P[original_index] = new_pos;
    }

    for (int i = 0; i < n; i++) {
        cout << P[i] << " ";
    }

    return 0;
}
