#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 말이 되고픈 원숭이
// https://www.acmicpc.net/problem/1600
int map[200+2][200+2] = {0,};
bool visited[200+2][200+2][30+1] = {0,};
int W, H; // W 가로길이 H 세로길이
int K;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int djx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int djy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

struct state{
    int x;
    int y;
    int jumpUsed;
    int moveCount;
};

int bfs(void){
    queue<state> q;
    q.push({1,1,0,0});

    visited[1][1][0] = true;

    while(!q.empty()){
        state current = q.front();
        q.pop();
        if(current.x == H && current.y == W) return current.moveCount;
        for(int i = 0; i < 4; i++){
            int afterX = current.x + dx[i];
            int afterY = current.y + dy[i];
            if(afterX < 1 || afterX > H || afterY < 1 || afterY > W) continue;
            if(map[afterX][afterY] == 0 && visited[afterX][afterY][current.jumpUsed] == false){
                visited[afterX][afterY][current.jumpUsed] = true;
                q.push({afterX, afterY, current.jumpUsed, current.moveCount+1});
            }
        }
        if(current.jumpUsed < K){
            for(int i = 0; i < 8; i++){
                int jumpX = current.x + djx[i];
                int jumpY = current.y + djy[i];
                if(jumpX < 1 || jumpX > H || jumpY < 1 || jumpY > W) continue;
                if(map[jumpX][jumpY] == 0 && visited[jumpX][jumpY][current.jumpUsed+1] == false){
                    visited[jumpX][jumpY][current.jumpUsed+1] = true;
                    q.push({jumpX, jumpY, current.jumpUsed+1, current.moveCount+1});
                }
            }
        }
    }

    return -1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(map, -1, sizeof(map));

    cin >> K;
    cin >> W >> H;

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> map[i][j];
        }
    }

    cout << bfs();
}