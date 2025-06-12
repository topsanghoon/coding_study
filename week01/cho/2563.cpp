#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, count = 0;
    cin >> N;

    vector<vector<int>> arr(100, vector<int>(100, 0));

    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        for (int k = 0; k < 10; k++) {
            for (int j = 0; j < 10; j++) {
                if (arr[x+k][y+j] == 0) {
                    arr[x+k][y+j] = 1;
                    count++;
                }
            }
        }
    }
    cout << count;

    return 0;
}
