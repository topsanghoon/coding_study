#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> graph;
vector<int> visited;
vector<int> answer;

int semi_dfs(int current, int current_step, stack<int>& path) {
    visited[current] = current_step;
    path.push(current);

    int next = graph[current];

    if (visited[next] == 0) {
        return semi_dfs(next, current_step, path);
    }
    else if (visited[next] == current_step) {
        return next;
    }
    else {
        return 0;
    }
}

int main() {
    int n;
    cin >> n;

    graph.resize(n + 1);
    visited.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> graph[i];
    }

    for (int i = 1, step = 1; i <= n; i++) {
        if (visited[i]) continue;

        stack<int> path;
        int cycle_start = semi_dfs(i, step, path);

        if (cycle_start != 0) {
            while(!path.empty()) {
                answer.push_back(path.top());
                if (path.top() == cycle_start) break;
                path.pop();
            }
        }

        step++;
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    cout << answer.size() << '\n';
    for (int x : answer) cout << x << '\n';

    return 0;
}
