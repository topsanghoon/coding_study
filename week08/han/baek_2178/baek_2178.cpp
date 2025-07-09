#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 미로 탐색
// https://www.acmicpc.net/problem/2178
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int answer = 1;
void bfs(vector<vector<int>> &map, int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(1,1));
    while(!q.empty()){
        pair<int, int> tempP = q.front();
        q.pop();
        if(tempP.first == x && tempP.second == y) break;
        for(int i = 0; i < 4; i++){
            int afterX = tempP.first + dx[i];
            int afterY = tempP.second + dy[i];
            if(map[afterX][afterY] == 1){
                map[afterX][afterY] = map[tempP.first][tempP.second] + 1;
                //cout << afterX << " " << afterY << "\n";
                q.push(make_pair(afterX,afterY));
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    vector<vector<int>> map(x+2,vector<int>(y+2));
    for(int i = 1; i <= x; i++){
        string temp;
        cin >> temp;
        for(int j = 1; j <= y; j++){
            map[i][j] = temp[j-1] - '0';
        }
    }

    bfs(map, x, y);

    // for(int i = 1; i <= x; i++){
    //     for(int j = 1; j <= y; j++){
    //         cout << map[i][j];
    //     }
    //     cout << "\n";
    // }
    cout << map[x][y];
    return 0;
}