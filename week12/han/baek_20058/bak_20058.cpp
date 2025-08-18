#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

// 마법사 상어와 파이어 스톰
// https://www.acmicpc.net/problem/20058

int N, Q;
int len = 0;
int map[64+2][64+2] = {0, };

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<int> Qarr;

int sum = 0;
    
void turn90(int n){
    int tempMap[66][66] = {0,};
    int size = 1 << n;
    for(int r = 1; r <= len; r += size){
        for(int c = 1; c <= len; c += size){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    tempMap[r+j][c+size-1-i] = map[r+i][c+j];
                }
            }
        }
    }

    for(int i = 1; i <= len; i++){
        for(int j = 1; j <= len; j++){
            map[i][j] = tempMap[i][j];
        }
    }

    bool iceMap[66][66] = {false,};

    for(int i = 1; i <= len; i++){
        for(int j = 1; j <= len; j++){
            int count = 0;
            for(int k = 0; k < 4; k++){
                int afterX = i + dx[k];
                int afterY = j + dy[k];
                if(afterX < 1 || afterX > len) continue;
                if(afterY < 1 || afterY > len) continue;
                if(map[afterX][afterY] > 0) count += 1;
            }
            if(count < 3) iceMap[i][j] = true;
        }
    }

    for(int i = 1; i <= len; i++){
        for(int j = 1; j <= len; j++){
            if(iceMap[i][j]) map[i][j] -= 1;
        }
    }

}

bool visited[66][66] = {false,};
int maxAnswer = 0;

int bfs(int x, int y){
    queue<pair<int,int>> q;
    int count = 0;
    visited[x][y] = true;
    q.push(make_pair(x,y));
    
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int afterX = curX + dx[i];
            int afterY = curY + dy[i];
            if(afterX < 1 || afterX > len) continue;
            if(afterY < 1 || afterY > len) continue;
            if(map[afterX][afterY] > 0 && visited[afterX][afterY] == false){
                visited[afterX][afterY] = true;
                q.push(make_pair(afterX, afterY));
            }
        }
        count++;
    }
    return count;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    len = 1 << N;
    for(int i = 1; i <= len; i++){
        for(int j = 1; j <= len; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < Q; i++){
        int temp;
        cin >> temp;
        Qarr.push_back(temp);
        turn90(temp);
    }

    // for(int i = 1; i <= len; i++){
    //     for(int j = 1; j <= len; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i = 1; i <= len; i++){
        for(int j = 1; j <= len; j++){
            if(map[i][j] > 0)sum += map[i][j];
            if(map[i][j] < 1 || visited[i][j] == true) continue;
            int temp = bfs(i,j);
            if(maxAnswer < temp) maxAnswer = temp;
        }
    }

    cout << sum << "\n";
    cout << maxAnswer;
}