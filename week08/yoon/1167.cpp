#include <iostream>
#include <vector>


using namespace std;


vector<vector<pair<int, int>>> graph;
vector <bool> visited;

int end_node = 0;
int max_dist = 0;

void dfs(int node, int dist) {

    if (dist > max_dist) {
        max_dist = dist;
        end_node = node;
    }

    visited[node] = true;
    for (pair<int, int> next_node : graph[node]) {
        if (!visited[next_node.first]) {
            dfs(next_node.first, dist + next_node.second);
        }
    }
}

int main() {
    int V;
    cin >> V;

    graph.resize(V+1);
    for (int i = 1; i <= V; ++i) {
        int from;
        cin >> from;
        while (true) {
            int to, weight;
            cin >> to;
            if (to == -1) break;
            cin >> weight;
            graph[from].push_back({to, weight});
        }
    }

    visited.resize(V+1, false);
    dfs(1, 0);

    fill(visited.begin(), visited.end(), false);
    max_dist = 0;
    dfs(end_node, 0);

    cout << max_dist << '\n';
    return 0;
}
