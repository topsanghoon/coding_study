#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int monkey_move_r[] = {0, 0, 1, -1};
const int monkey_move_c[] = {1, -1, 0, 0};
const int horse_move_r[] = {1, -1, 1, -1, 2, 2, -2, -2};
const int horse_move_c[] = {2, 2, -2, -2, 1, -1, 1, -1};
bool out_of_map(int r, int c, int n, int m){
    if(r < 0 || r >= n || c < 0 || c >= m) return true;
    return false;
}

int main(){

    int k;
    cin >> k;

    int n, m;
    cin >> m >> n;
    
    vector <vector<int>> map(n, vector<int>(m));
    for(vector <int> &row : map){
        for(int & point : row){
            cin >> point;
        }
    }
    int goal_r = n - 1;
    int goal_c = m - 1;


    priority_queue <tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> q;
    vector<vector<vector<int>>> cost_map(n, vector<vector<int>> (m, vector<int> (k + 1, 1e9)));
    q.push({0, 0, 0, 0});
    cost_map[0][0][0] = 0;

    while(!q.empty()){
        auto[ cur_cnt, cur_k, cur_r, cur_c] = q.top();
        q.pop();

        if(goal_r == cur_r && goal_c == cur_c){
            cout << cur_cnt;
            return 0;
        }
        

        if(cur_k < k){
            for(int i = 0; i < 8; i++){

                int new_r = cur_r + horse_move_r[i];
                int new_c = cur_c + horse_move_c[i];

                if(out_of_map(new_r, new_c, n, m)) continue;
                if(map[new_r][new_c] == 1) continue;
                if(cost_map[new_r][new_c][cur_k + 1] <= cur_cnt + 1) continue;
                
                cost_map[new_r][new_c][cur_k + 1] = cur_cnt + 1;
                q.push({cur_cnt + 1, cur_k + 1, new_r, new_c});
            }
        }

        for(int i = 0; i < 4; i++){
            int new_r = cur_r + monkey_move_r[i];
            int new_c = cur_c + monkey_move_c[i];

            if(out_of_map(new_r, new_c, n, m)) continue;
            if(map[new_r][new_c] == 1) continue;
            if(cost_map[new_r][new_c][cur_k] <= cur_cnt + 1) continue;

            cost_map[new_r][new_c][cur_k] = cur_cnt + 1;
            q.push({cur_cnt + 1, cur_k, new_r, new_c});
        }
    }

    cout << -1;

    return 0;
}