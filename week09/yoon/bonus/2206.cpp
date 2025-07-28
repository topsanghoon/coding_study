#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <string>

using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> Map(N);
    for (int i = 0; i < N; i++)
        cin >> Map[i];

    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    queue<tuple<int, int, int, int>> q;  // r, c, broken, dist
    q.push({0, 0, 0, 1});
    visited[0][0][0] = true;

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cout << Map[i][j] << " ";
    //     }
    // }

    int answer = -1;
    while (!q.empty()) {
        auto [r, c, broken, dist] = q.front(); q.pop();

        if (r == N - 1 && c == M - 1) {
            answer = dist;
            break;  // BFS니까 먼저 도달한게 최소 거리임
        }

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            // 다음칸이 벽이 아니고, 방문한 적 없다면
            if (Map[nr][nc] == '0' && !visited[nr][nc][broken]) {
                visited[nr][nc][broken] = true;
                q.push({nr, nc, broken, dist + 1});
            }
            // 벽이고 아직 벽을 부순 적이 없다면
            else if (Map[nr][nc] == '1' && broken == 0 && !visited[nr][nc][1]) {
                visited[nr][nc][1] = true;
                q.push({nr, nc, 1, dist + 1});
            }
        }
    }

    cout << answer;
    return 0;
}
