#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, 1, -1};
int main(){

    int N, M;
    cin >> M >> N;

    vector <vector<int>> map (N, vector<int> (M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    int answer = -1;
    queue <tuple<int, int, int>> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 1) q.push({i, j, 0});
        }
    }

    while(!q.empty()){
        int c_r, c_c, cnt;
        tie(c_r, c_c, cnt) = q.front();
        q.pop();
        answer = cnt;
        for(int i = 0; i < 4; i++){
            int n_r = c_r + dr[i];
            int n_c = c_c + dc[i];

            if(n_r <0 || n_r >= N || n_c < 0 || n_c >= M) continue;
            if(map[n_r][n_c] != 0) continue;

            map[n_r][n_c] = cnt + 1;
            q.push({n_r, n_c, cnt + 1});
        }
    }

    for(int i = 0; i < N; i++){
       for(int j = 0; j < M; j++){
            if(map[i][j] == 0) {
                cout << "-1";
                return 0;
            }
       } 
    }
    cout << answer;

    return 0;
}