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

        graph[x][y].push_back({a, b});
    }

    int answer = 0;

    vector<vector<bool>> Lights(N, vector<bool> (N, false));
    queue<tuple<int, int>> q;
    q.push({0, 0});
    Lights[0][0] = true;

    while(!q.empty()){
        auto[cur_x, cur_y] = q.front();
        q.pop();

        answer++;
        for(int i = 0; i < 4; i++){
            int new_x, new_y;
            new_x = cur_x + dx[i];
            new_y = cur_y + dy[i];
            if() continue;
        }
    }

    


    return 0;
}