#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;


const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> default_map (n, vector<int>(m));
    vector<pair<int, int>> blank_rc;
    vector<pair<int, int>> virus_rc;
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> default_map[i][j];
            if(default_map[i][j] == 0) blank_rc.push_back({i, j});
            else if(default_map[i][j] == 2) virus_rc.push_back({i, j});
        }
    }

    int blank_size = blank_rc.size();

    int ans = 0;
    for(int i = 0; i < blank_size - 2; i++){
        for(int j = i+1; j < blank_size - 1; j++){
            for(int k = j+1; k < blank_size; k++){
                vector<vector<int>> temp_map = default_map;
                temp_map[blank_rc[i].first][blank_rc[i].second] = 1;
                temp_map[blank_rc[j].first][blank_rc[j].second] = 1; 
                temp_map[blank_rc[k].first][blank_rc[k].second] = 1; 

                queue<tuple<int, int>> q; //r, c
                for(auto [vr, vc] : virus_rc){
                    q.push({vr, vc});
                }
                int total_balnk = blank_size - 3;
                while(!q.empty()){
                    if(total_balnk < ans) break;
                    auto [cr, cc] = q.front();
                    q.pop();

                    for(int dir = 0; dir < 4; dir++){
                        int nr = cr + dr[dir];
                        int nc = cc + dc[dir];

                        if(nr < 0 || nr >= n || nc < 0 || nc>= m) continue;
                        if(temp_map[nr][nc] != 0) continue;

                        total_balnk--;
                        temp_map[nr][nc] = 2;
                        q.push({nr, nc});
                    }

                }

                // cout <<"\n\n";
                // for(int ii = 0; ii < n; ii++){
                //     for(int jj = 0; jj < m; jj++){
                //         cout << temp_map[ii][jj] << " ";
                //     }
                //     cout <<"\n";
                // }
                // cout <<"\n\n";

                ans = max(ans, total_balnk);

            }
        }
    }

    cout << ans;
    return 0;
}