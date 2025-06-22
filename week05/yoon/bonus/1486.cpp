#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cctype>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int N, M, T, D;
vector<vector<int>> height;

vector<vector<int>> dijkstra(int sx, int sy, bool reverse) {
    vector<vector<int>> dist(N, vector<int>(M, 1e9));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    dist[sx][sy] = 0;
    pq.push({0, sx, sy});

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top(); pq.pop();
        if (cost > dist[x][y]) continue;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            int diff = height[nx][ny] - height[x][y];
            if (abs(diff) > T) continue;

            int move_cost;
            if (reverse) {
                // (x,y) → (nx,ny): 실제는 역방향이지만, cost 계산은 그대로
                if (diff < 0) move_cost = diff * diff;  // 오르막 (실제는 내리막 역방향)
                else move_cost = 1;                     // 내리막
            } else {
                if (diff > 0) move_cost = diff * diff;  // 오르막
                else move_cost = 1;                     // 내리막
            }

            int new_cost = cost + move_cost;
            if (new_cost < dist[nx][ny]) {
                dist[nx][ny] = new_cost;
                pq.push({new_cost, nx, ny});
            }
        }
    }

    return dist;
}

int main() {
    cin >> N >> M >> T >> D;
    height.assign(N, vector<int>(M));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            if (isupper(c)) height[i][j] = c - 'A';
            else height[i][j] = c - 'a' + 26;
        }

    // 1. (0,0) → 모든 위치까지
    auto to_map = dijkstra(0, 0, false);
    // 2. 모든 위치 → (0,0)까지 (역방향)
    auto from_map = dijkstra(0, 0, true);

    int max_h = height[0][0];  // 시작점 포함
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            if (to_map[i][j] + from_map[i][j] <= D)
                max_h = max(max_h, height[i][j]);
        }

    cout << max_h << '\n';
    return 0;
}
