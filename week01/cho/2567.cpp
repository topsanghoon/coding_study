#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, count = 0;
    cin >> N;

    vector<vector<int>> arr(100, vector<int>(100, 0));
    int move_x[] = {-1, 0, 1, 0};  
    int move_y[] = {0, 1, 0, -1};

    
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        for (int k = 0; k < 10; k++) {
            for (int j = 0; j < 10; j++) {
                arr[x + k][y + j] = 1;
            }
        }
    }

    
    for (int a = 0; a < 100; a++) {
        for (int b = 0; b < 100; b++) {
            if (arr[a][b] == 1) {
                for (int c = 0; c < 4; c++) {
                    int x1 = a + move_x[c];
                    int y1 = b + move_y[c];
                    
                    if (x1 < 0 || x1 >= 100 || y1 < 0 || y1 >= 100 || arr[x1][y1] == 0) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count;
    return 0;
}
