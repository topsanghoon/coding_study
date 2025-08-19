#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        int n, d, c;
        cin >> n >> d >> c;
        
        vector<vector<pair<int, int>>> graph(n+1);
        for(int i = 0; i < d; i++){
            int to, from, time;
            cin >> to >> from >> time;

            graph[from].push_back({to, time});
        }

        vector<int> cost(n+1, 1e9);
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> q;
        q.push({0, c});
        cost[c] = 0;

        while(!q.empty()){
            auto [cur_time, from] = q.top();
            q.pop();

            for(auto [to, target_cost] : graph[from]){
                if(cost[to] <= target_cost + cur_time) continue;

                cost[to] = target_cost + cur_time;
                q.push({target_cost + cur_time, to});
            }
        }


        int answer_num = 0, answer_time = 0;
        for(int i = 1; i <= n; i++){
            if(cost[i] != 1e9){
                answer_num++;
                answer_time = max(answer_time, cost[i]);
            }
        }
        
        cout << answer_num << " " << answer_time << "\n";
    }

    return 0;
}