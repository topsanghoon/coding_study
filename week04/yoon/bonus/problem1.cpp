#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> cost_map;
bool visited[14] = {false};
int min_cost = 1e9;

void dfs(int depth, int current, int cost_sum) {
    if (cost_sum >= min_cost) return;  // 가지치기

    if (depth == n - 1) { // 마지막 도시까지 도달
        if (cost_map[current][0] != 0) { // 0번 도시로 돌아갈 수 있다면
            min_cost = min(min_cost, cost_sum + cost_map[current][0]);
        }
        return;
    }

    for (int next = 1; next < n; ++next) {
        if (!visited[next] && cost_map[current][next] != 0) {
            visited[next] = true;
            dfs(depth + 1, next, cost_sum + cost_map[current][next]);
            visited[next] = false;
        }
    }
}

int main() {
    cin >> n;
    cost_map.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> cost_map[i][j];

    visited[0] = true;  // 시작 도시 방문 처리
    dfs(0, 0, 0);        // 0번 도시부터 시작
    cout << min_cost << "\n";
    return 0;
}
