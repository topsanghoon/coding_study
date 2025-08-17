#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<long long>> graph(n + 1 , vector<long long>(n + 1, 1e9));
    vector<vector<vector<int>>> city(n + 1 , vector<vector<int>> (n + 1));
    for(int i = 0; i < m; i++){
        long long from, to, cost;
        cin >> from >> to >> cost;

        if(cost < graph[from][to]){
            graph[from][to] = cost;
            city[from][to].clear();
            city[from][to].push_back(from);
            city[from][to].push_back(to);
        }
    }

    for(int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(graph[j][k] > graph[j][i] + graph[i][k]){
                    graph[j][k] = graph[j][i] + graph[i][k];
                    city[j][k].clear();

                    for(int list : city[j][i]) city[j][k].push_back(list);
                    city[j][k].pop_back();
                    for(int list : city[i][k]) city[j][k].push_back(list);
                }
            }
        }
    }

    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == 1e9) cout << 0 << " ";
            else cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << city[i][j].size() << " ";
            for(int c : city[i][j]) cout << c << " ";
            cout << "\n";
        }
    }

    return 0;
}