#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

const int dr[] = {1, -1, 0, 0}; // 동서남북
const int dc[] = {0, 0, 1, -1};

// BOJ에서 주어지는 방향을 0~3으로 매핑하는 함수 (1~4 → 동서남북 → 2, 3, 0, 1)
int convert_dir(int d) {
    if (d == 1) return 2; // 동
    if (d == 2) return 3; // 서
    if (d == 3) return 0; // 남
    return 1;             // 북
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> map(M, vector<int>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    int r1, c1, dir1, r2, c2, dir2;
    cin >> r1 >> c1 >> dir1;
    cin >> r2 >> c2 >> dir2;

    r1--, c1--, r2--, c2--;  // 0-indexed로 변환
    dir1 = convert_dir(dir1);
    dir2 = convert_dir(dir2);

    const int INF = 0x7FFFFFFF;
    vector<vector<vector<int>>> cost(M, vector<vector<int>>(N, vector<int>(4, INF)));
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> q;

    cost[r1][c1][dir1] = 0;
    q.push({0, r1, c1, dir1});  // cnt, r, c, dir

    while (!q.empty()) {
        int cnt, r, c, dir;
        tie(cnt, r, c, dir) = q.top(); q.pop();

        if (r == r2 && c == c2 && dir == dir2) {
            cout << cnt << "\n";
            return 0;
        }

        // 1. 회전 (왼쪽 or 오른쪽 90도)
        for (int i = 1; i <= 2; i++) {
            int ndir = (dir + i) % 4;
            if (cost[r][c][ndir] > cnt + 1) {
                cost[r][c][ndir] = cnt + 1;
                q.push({cnt + 1, r, c, ndir});
            }
            ndir = (dir + 4 - i) % 4;  // 반대 방향도
            if (cost[r][c][ndir] > cnt + 1) {
                cost[r][c][ndir] = cnt + 1;
                q.push({cnt + 1, r, c, ndir});
            }
        }

        // 2. 전진 (1~3칸)
        int nr = r, nc = c;
        for (int k = 1; k <= 3; k++) {
            nr += dr[dir];
            nc += dc[dir];
            if (nr < 0 || nr >= M || nc < 0 || nc >= N || map[nr][nc]) break;
            if (cost[nr][nc][dir] > cnt + 1) {
                cost[nr][nc][dir] = cnt + 1;
                q.push({cnt + 1, nr, nc, dir});
            }
        }
    }

    return 0;
}
