#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
const int INF = 1e9;

int N, M, X;
vector<vector<pii>> graph, reverse_graph;

vector<int> dijkstra(int start, const vector<vector<pii>>& g) {
    vector<int> dist(N + 1, INF);
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        if (cost > dist[cur]) continue;

        for (auto [next, c] : g[cur]) {
            if (dist[next] > cost + c) {
                dist[next] = cost + c;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}

int main() {
    cin >> N >> M >> X;

    graph.resize(N + 1);
    reverse_graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].emplace_back(to, cost);
        reverse_graph[to].emplace_back(from, cost);  // 간선 뒤집기
    }

    vector<int> to_X = dijkstra(X, reverse_graph);  // i → X
    vector<int> from_X = dijkstra(X, graph);        // X → i

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (to_X[i] == INF || from_X[i] == INF) continue;
        ans = max(ans, to_X[i] + from_X[i]);
    }

    cout << ans << '\n';
    return 0;
}
