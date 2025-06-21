#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dir_x[4] = {1, -1, 0, 0};
const int dir_y[4] = {0, 0, 1, -1};

int row, col;
vector<vector<int>> cheese_map;

#ifndef ONLINE_JUDGE
void print_cheese(){
    cout << "\n\n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j ++){
            cout << cheese_map[i][j] << " ";
        } cout << "\n";
    } // 맵생성
}
#endif

void resize_cheese_map() {
    cheese_map.resize(row, vector<int>(col));
}

void DFS_air(int x, int y) {
    cheese_map[x][y] = -1; // 외부 공기 표시

    for (int d = 0; d < 4; d++) {
        int nx = x + dir_x[d];
        int ny = y + dir_y[d];

        if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
        if (cheese_map[nx][ny] == 0) {
            DFS_air(nx, ny);
        }
    }
}

int count_cheese() {
    int cnt = 0;
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (cheese_map[i][j] == 1) cnt++;
    return cnt;
}

void update_external_air() {
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (cheese_map[i][j] == -1)
                cheese_map[i][j] = 0; // reset to air

    DFS_air(0, 0); // 다시 외부 공기 표시
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> row >> col;
    resize_cheese_map();

    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            cin >> cheese_map[i][j];

    // 초기 외부 공기 표시
    DFS_air(0, 0);

    int time = 0;
    int last_cheese = count_cheese();

    while (true) {
        vector<pair<int, int>> to_melt;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (cheese_map[i][j] != 1) continue;

                for (int d = 0; d < 4; ++d) {
                    int ni = i + dir_x[d];
                    int nj = j + dir_y[d];

                    if (ni < 0 || ni >= row || nj < 0 || nj >= col) continue;
                    if (cheese_map[ni][nj] == -1) {
                        to_melt.push_back({i, j});
                        break;
                    }
                }
            }
        }

        if (to_melt.empty()) break;

        last_cheese = count_cheese();
        for (auto& p : to_melt) {
            cheese_map[p.first][p.second] = 0; // 녹이기
        }

        update_external_air(); // 외부 공기 확장

        #ifndef ONLINE_JUDGE
        print_cheese();
        #endif

        time++;
    }

    cout << time << '\n' << last_cheese << '\n';
    return 0;
}
