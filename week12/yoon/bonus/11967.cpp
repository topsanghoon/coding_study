#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int main(){

    int N, M;
    cin >> N >> M;

    vector<vector<vector<tuple<int, int>>>> graph (N, vector<vector<tuple<int, int>>> (N));
    for(int i = 0; i < M; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        graph[--x][--y].push_back({--a, --b});
    }

    int answer = 1;

    vector<vector<bool>> Lights(N, vector<bool> (N, false));
    vector<vector<bool>> Visited(N, vector<bool> (N, false));
    queue<tuple<int, int>> q;
    q.push({0, 0});
    Lights[0][0] = true;
    Visited[0][0] = true;

    while(!q.empty()){
        auto[cur_x, cur_y] = q.front();
        q.pop();

        for(auto[target_x, target_y] : graph[cur_x][cur_y]){
            if(Lights[target_x][target_y]) continue;
            Lights[target_x][target_y] = true;
            answer++;
            
            for(int i = 0; i < 4; i++){
                int new_x, new_y;
                new_x = target_x + dx[i];
                new_y = target_y + dy[i];

                if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= N) continue;
                if(Visited[new_x][new_y]){
                    q.push({target_x, target_y});                                                    
                    Visited[target_x][target_y] = true;
                    break;
                }
            }
        }

        for(int i = 0; i < 4; i++){
            int new_x, new_y;
            new_x = cur_x + dx[i];
            new_y = cur_y + dy[i];
            if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= N) continue;
            if (!Visited[new_x][new_y] && Lights[new_x][new_y]) {
                q.push({new_x, new_y});
                Visited[new_x][new_y] = true;
            }
        }


    }



    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << Visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    cout << answer;


    


    return 0;
}