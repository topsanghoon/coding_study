#include <iostream>
#include <queue>

using namespace std;

// 벽 부수고 이동하기
// https://www.acmicpc.net/problem/2206

char map[1000+2][1000+2];
bool visited[1000+2][1000+2][2] = {0,};
int N, M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct _node{
    int x;
    int y;
    int breakCnt;
    int moveCnt;
}typedef node;

queue<node> q;

int bfs(void){

    node first = {1, 1, 0, 1};
    q.push(first);
    visited[1][1][0] = true;
    
    while(!q.empty()){
        node temp = q.front();
        q.pop();
        int cur_x = temp.x;
        int cur_y = temp.y;
        int cur_breakCnt = temp.breakCnt;
        int cur_cnt = temp.moveCnt;

        if(cur_x == N && cur_y == M){
            return cur_cnt;
        }

        for(int i = 0; i < 4; i++){
            int afterX = cur_x + dx[i];
            int afterY = cur_y + dy[i];
            if(cur_breakCnt < 1){
                if(map[afterX][afterY] == '0' && visited[afterX][afterY][0] == false){
                    q.push({afterX, afterY, cur_breakCnt, cur_cnt + 1});
                    visited[afterX][afterY][0] = true;
                }
                if(map[afterX][afterY] == '1' && visited[afterX][afterY][1] == false){
                    q.push({afterX, afterY, cur_breakCnt + 1, cur_cnt + 1});
                    visited[afterX][afterY][1] = true;
                }
            }
            else if(cur_breakCnt == 1){
                if(map[afterX][afterY] == '0' && visited[afterX][afterY][1] == false){
                    q.push({afterX, afterY, cur_breakCnt, cur_cnt + 1});
                    visited[afterX][afterY][1] = true;
                }
            }
        }
    }
    return -1;
}

int main(void){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        string temp_str;
        cin >> temp_str;
        for(int j = 1; j <= M; j++){
            map[i][j] = temp_str[j-1];
        }
    }
    
    cout << bfs();
}