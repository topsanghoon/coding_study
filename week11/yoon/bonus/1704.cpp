#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int u, v;
        cin >> u >> v;

        vector<vector<int>> graph(u + 1);
        for(int i = 0; i < v; i++){
            int temp1, temp2;
            cin >> temp1 >> temp2;

            graph[temp1].push_back(temp2);
            graph[temp2].push_back(temp1);
        }

        vector<int> RedOrBlue (u + 1, -1);
        vector<bool> visited (u + 1, false);

        queue <tuple<int, int>> q; //현재, 그룹

        bool YES = true;
        for(int i = 1; i <= u; i++){
            if(visited[i]) continue;

            RedOrBlue[i] = 0;
            visited[i] = true;
            q.push({i, 0});

            while(!q.empty() && YES){
                auto[current, group] = q.front(); q.pop();

                for(int next : graph[current]){
                    
                    if(RedOrBlue[next] == group){
    
                        YES = false;
                        break;
                    }
                    if(visited[next]) continue;

                    q.push({next, (group+1)%2});
                    visited[next] = true;
                    RedOrBlue[next] = (group+1)%2;
                }
            }
        }
        
        auto min_value = *min_element(RedOrBlue.begin() + 1, RedOrBlue.end());

        if(YES && min_value != -1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }


    return 0;
}