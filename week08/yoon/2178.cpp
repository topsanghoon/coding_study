#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int main(){

    int N, M;
    cin >> N >> M;

    vector<string> map(N);

    for(int i = 0; i < N; i++) cin >> map[i];

    vector<vector<int>> visited (N, vector<int> (M, 1e9));
    priority_queue <tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    
    visited[0][0] = 0;
    q.push({1, 0, 0});
    while(!q.empty()){
        int cx, cy, c_count;
        tie(c_count, cx, cy) = q.top();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= N || ny <0 || ny >= M) continue;
            if(map[nx][ny] == '0') continue;
            if(visited[nx][ny] <= c_count+1) continue;

            visited[nx][ny] = c_count+1;
            q.push({c_count+1, nx, ny});
        }
    }

    cout << visited[N-1][M-1];
}