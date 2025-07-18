#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, k;
    cin >> N >> M >> k;

    vector<string> map (N);
    for(int i = 0; i < N; i++) cin >> map[i];

    int target_r = N - 1;
    int target_c = M - 1;

    vector<vector<vector<bool>>> visited (N, vector<vector<bool>>(M, vector<bool> (k+1 ,false)));
    queue <tuple<int, int, int, int>> q;

    q.push({0, 0, 1, 0});
    visited[0][0][0] = true;

    int ans = -1;
    while(!q.empty()){
        auto[cr, cc, cnt, broken_num] = q.front();
        q.pop();

        if(target_c == cc && target_r == cr) {
            ans = cnt;
            break;
        }

        for(int i = 0; i < 4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            if(map[nr][nc] == '0' && visited[nr][nc][broken_num] == false){
                q.push({nr, nc, cnt + 1, broken_num});
                visited[nr][nc][broken_num] = true;
            }
            else if(map[nr][nc] == '1' && broken_num < k && visited[nr][nc][broken_num + 1] == false){
                q.push({nr, nc, cnt + 1, broken_num + 1});
                visited[nr][nc][broken_num + 1] = true;
            }
        }
    }

    cout << ans;

    return 0;
}