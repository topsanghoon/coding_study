#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <tuple>

using namespace std;



void Rotate(vector<vector<int>>& map, int current_size, int map_size){

    for(int i = 0; i < map_size; i += current_size){
        for(int j = 0; j < map_size; j += current_size){

            vector<vector<int>> temp(current_size, vector<int> (current_size));
            for(int r = 0; r < current_size; r++){
                for(int c = 0; c < current_size; c++){
                    temp[r][c] = map[i + r][j + c];
                }
            }

            for(int r = 0; r < current_size; r++){
                for(int c = 0; c < current_size; c++){
                    map[i + r][j + c] = temp[current_size - 1 - c][r];
                }
            }
        }
    }

    return;
}

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int main(){

    int N, Q;
    cin >> N >> Q;

    int map_size = 1 << N;
    vector<vector<int>> map (map_size, vector<int>(map_size));

    for(int i = 0; i < map_size; i++)
        for(int j = 0; j < map_size; j++) 
            cin >> map[i][j];

    

    // for(int i = 0; i < map_size; i++){
    //     for(int j = 0; j < map_size; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    for(int step = 0; step < Q; step++){
        int L;
        cin >> L;

        int current_size = 1 << L;

        Rotate(map, current_size, map_size);

        vector<vector<int>> temp = map;
        for(int i = 0; i < map_size; i++){
            for(int j = 0; j < map_size; j++){
                if(!map[i][j]) continue;
                int cnt = 0;
                for(int dir = 0; dir < 4; dir++){
                    int nr = i + dr[dir];
                    int nc = j + dc[dir];

                    if(nr < 0 || nc < 0 || nr >= map_size || nc >= map_size) continue;
                    if(map[nr][nc]) cnt++;
                }

                if(cnt >= 3) continue;
                temp[i][j]--;
            }
        }

        map = temp;
    }


    // for(int i = 0; i < map_size; i++){
    //     for(int j = 0; j < map_size; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    int left_ice = 0, max_size = 0;
    queue <tuple<int, int>> q;
    vector<vector<bool>> visited (map_size, vector<bool>(map_size, false));
    for(int i = 0; i < map_size; i++){
        for(int j = 0; j < map_size; j++){

            if(visited[i][j] || !map[i][j]) {
                visited[i][j] = true;             
                continue;
            }

            int cur_ice_size = 0;
            visited[i][j] = true;   
            q.push({i, j});

            while(!q.empty()){
                auto[cr, cc] = q.front();
                q.pop();
  
                left_ice += map[cr][cc];
                cur_ice_size++;

                for(int dir = 0; dir < 4; dir++){
                    int nr = cr + dr[dir];
                    int nc = cc + dc[dir];

                    if(nr < 0 || nc < 0 || nr >= map_size || nc >= map_size) continue;
                    if(visited[nr][nc] || !map[nr][nc]) continue;

                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }

            max_size = max(max_size, cur_ice_size);

        }
    }

    //if(left_ice == 0) cout << 0;
    cout << left_ice << "\n" << max_size;

    return 0;
}