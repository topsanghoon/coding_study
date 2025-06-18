// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// vector<vector<int>> previous_map;  // 이전 맵
// vector<vector<int>> current_map(1, vector<int>(1, 0));  // 초기 맵 (1x1, 값은 0)

// void init_map(int n, int k) {
//     vector<vector<int>> temp_map(n, vector<int>(n));
//     int center_start = (n - k) / 2;
//     int center_end = center_start + k;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (i >= center_start && i < center_end && j >= center_start && j < center_end)
//                 temp_map[i][j] = 1;
//             else
//                 temp_map[i][j] = 0;
//         }
//     }
//     previous_map = current_map;
//     current_map = temp_map;
// }

// void new_map(int s, int n, int k, int now) {
//     if (now == s) return;
//     new_map(s, n, k, now + 1);

//     int current_size = current_map.size();
//     int new_size = current_size * n;
//     vector<vector<int>> temp_map(new_size, vector<int>(new_size));
//     previous_map = current_map;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             int x_offset = i * current_size;
//             int y_offset = j * current_size;

//             if (i >= (n - k) / 2 && i < (n - k) / 2 + k && j >= (n - k) / 2 && j < (n - k) / 2 + k) {
//                 // 중심 영역: 1로 채우기
//                 for (int ii = 0; ii < current_size; ii++) {
//                     for (int jj = 0; jj < current_size; jj++) {
//                         temp_map[x_offset + ii][y_offset + jj] = 1;
//                     }
//                 }
//             } else {
//                 // 외곽: 이전 맵 복사
//                 for (int ii = 0; ii < current_size; ii++) {
//                     for (int jj = 0; jj < current_size; jj++) {
//                         temp_map[x_offset + ii][y_offset + jj] = current_map[ii][jj];
//                     }
//                 }
//             }
//         }
//     }

//     current_map = temp_map;
// }

// int main() {
//     int s, n, k, R1, R2, C1, C2;
//     cin >> s >> n >> k >> R1 >> R2 >> C1 >> C2;

//     init_map(n, k);
//     new_map(s, n, k, 1);

//     for (int i = R1; i <= R2; i++) {
//         for (int j = C1; j <= C2; j++) {
//             cout << current_map[i][j];
//         }
//         cout << '\n';
//     }

//     return 0;
// }

//아직 진행중중
#include <iostream>
#include <cmath>
using namespace std;

bool is_black(int s, int n, int k, int r, int c) {
    if (s == 0) return false;

    int len = pow(n, s - 1);
    int center_start = (n - k) / 2;
    int center_end = center_start + k;

    int row_block = r / len;
    int col_block = c / len;

    if (center_start <= row_block && row_block < center_end &&
        center_start <= col_block && col_block < center_end) {
        return true;
    }

    return is_black(s - 1, n, k, r % len, c % len);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int s, n, k, R1, R2, C1, C2;
    cin >> s >> n >> k >> R1 >> R2 >> C1 >> C2;

    for (int i = R1; i <= R2; i++) {
        for (int j = C1; j <= C2; j++) {
            cout << (is_black(s, n, k, i, j) ? 1 : 0);
        }
        cout << '\n';
    }

    return 0;
}
