#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

int N, M;
vector<string> lake;
pair<int, int> swan1, swan2;

vector<vector<bool>> visited_swan, visited_water;
queue<pair<int, int>> swan_q, swan_next_q;
queue<pair<int, int>> water_q, water_next_q;

bool in_range(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

// 백조 BFS: 오늘 가능한 이동만 swan_q, 내일 가능한 얼음은 swan_next_q
bool move_swan() {
    while (!swan_q.empty()) {
        auto [r, c] = swan_q.front(); swan_q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (!in_range(nr, nc) || visited_swan[nr][nc]) continue;

            visited_swan[nr][nc] = true;

            if (lake[nr][nc] == '.') {
                swan_q.push({nr, nc});
            }
            else if (lake[nr][nc] == 'X') {
                swan_next_q.push({nr, nc});
            }
            else if (lake[nr][nc] == 'L') {
                return true;  // 다른 백조 만남
            }
        }
    }
    return false;
}

// 얼음 녹이기: 현재 물 주변의 X를 녹이고 내일 물로 바꿈
void melt() {
    while (!water_q.empty()) {
        auto [r, c] = water_q.front(); water_q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (!in_range(nr, nc) || visited_water[nr][nc]) continue;

            if (lake[nr][nc] == 'X') {
                visited_water[nr][nc] = true;
                lake[nr][nc] = '.';  // 녹임
                water_next_q.push({nr, nc});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    lake.resize(N);
    visited_swan.assign(N, vector<bool>(M, false));
    visited_water.assign(N, vector<bool>(M, false));

    bool found = false;

    for (int i = 0; i < N; i++) {
        cin >> lake[i];
        for (int j = 0; j < M; j++) {
            if (lake[i][j] == 'L') {
                if (!found) {
                    swan1 = {i, j};
                    found = true;
                } else {
                    swan2 = {i, j};
                }
            }
            if (lake[i][j] != 'X') {
                visited_water[i][j] = true;
                water_q.push({i, j});
            }
        }
    }

    swan_q.push(swan1);
    visited_swan[swan1.first][swan1.second] = true;

    int day = 0;
    while (true) {
        if (move_swan()) {
            cout << day << endl;
            break;
        }
        melt();
        swap(swan_q, swan_next_q);
        swap(water_q, water_next_q);
        day++;
    }

    return 0;
}
