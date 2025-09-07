#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N, M;
long long answer = 0;
vector<int> depth;

struct Edge {
    int to;
    int id;
};

void DFS(vector<vector<Edge>> &graph, int u, int parent_edge_id, int d) {
    depth[u] = d;

    for (auto [v, eid] : graph[u]) {
        if (eid == parent_edge_id) continue;

        if (depth[v] == 0) {
            DFS(graph, v, eid, d + 1);
        } else if (depth[v] < depth[u]) {
            int len = depth[u] - depth[v] + 1;
            answer += 1LL * len * len;
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<vector<Edge>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, i});
        graph[to].push_back({from, i});
    }

    depth.assign(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        if (depth[i] == 0) {
            DFS(graph, i, -1, 1);
        }
    }

    cout << answer << "\n";
    return 0;
}
