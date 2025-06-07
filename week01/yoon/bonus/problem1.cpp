#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> leaves(n);
    for (int i = 0; i < n; ++i) {
        cin >> leaves[i];
    }

    sort(leaves.begin(), leaves.end());

    int count = 0;


    for (int i = 0; i < n; ++i) {         // a
        for (int j = i + 1; j < n; ++j) { // b
            int jump1 = leaves[j] - leaves[i];
            for (int k = j + 1; k < n; ++k) { // c
                int jump2 = leaves[k] - leaves[j];
                if (jump2 >= jump1 && jump2 <= 2 * jump1) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}
