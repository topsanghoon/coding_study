#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

const int dir_x[4] = {1, -1, 0, 0};
const int dir_y[4] = {0, 0, 1, -1};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int row, col;
    cin >> col >> row;

    vector <string> jug_map;
    for(int i = 0; i < row; i++){
        string temp;
        cin >> temp;
        jug_map.push_back(temp);
    }
    int x, y;
    cin >> x >> y;

    int max_time = 0;
    queue <tuple<int, int, int>> q;
    vector <vector<bool>> visited (row, vector <bool> (col, false));

    q.push({3, y-1, x-1});
    visited[y-1][x-1] = true;
    
    while(!q.empty()){
        int cx, cy, cur_time;
        tie(cur_time, cx, cy)= q.front();
        q.pop();
        jug_map[cx][cy] = '0';
        
        max_time = max(max_time, cur_time);
        for(int i = 0; i < 4; i++){
            int nx = cx + dir_x[i];
            int ny = cy + dir_y[i];

            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if(visited[nx][ny] == true) continue;
            if(jug_map[nx][ny] != '1') continue;
            q.push({cur_time + 1, nx, ny});
            visited[nx][ny] = true;
        }
    }


    cout << (max_time) << "\n";

    int cnt = 0;
    for(string s : jug_map){
        for(char c : s){
            if(c == '1') cnt++;
        }
    }

    cout << cnt;
    return 0;
}
