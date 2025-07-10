#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int dr[] = {0, 0, 0, 0, 1, -1};
const int dc[] = {0, 0, 1, -1, 0, 0};
const int dh[] = {1, -1, 0, 0, 0, 0};
int main(){

    int M, N, H;
    cin >> M >> N >> H;

    int tomato[100][100][100] = {0}; // H, M, N
    for(int h = 0; h < H; h++){
        for(int n = 0; n < N; n++){      // 세로
            for(int m = 0; m < M; m++){  // 가로
                cin >> tomato[h][n][m];  // 세로가 두 번째 인덱스여야 함
            }
        }
    }

    queue <tuple<int, int, int, int>> q;
    for(int h = 0; h < H; h++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(tomato[h][i][j] == 1) q.push({h, i, j, 0}); 
            }
        }
    }

    int answer;
    while(!q.empty()){
        int c_r, c_c, c_h, cnt;
        tie(c_h,c_r, c_c, cnt) = q.front();
        q.pop();

        answer = cnt;

        for(int i = 0; i < 6; i++){
            int n_r = c_r + dr[i];
            int n_c = c_c + dc[i];
            int n_h = c_h + dh[i];

            if(n_r < 0 || n_r >= N || n_c < 0 || n_c >= M || n_h <0 || n_h >= H) continue;
            if(tomato[n_h][n_r][n_c] != 0) continue;

            tomato[n_h][n_r][n_c] = cnt + 1;
            q.push({n_h, n_r, n_c, cnt + 1});
        }
    }

    for(int h = 0; h < H; h++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(tomato[h][i][j] == 0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << answer;

    return 0;
}