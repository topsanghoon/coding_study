#include <vector>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
/*
9 9
3 5 2 8
*/

const int dr[] = {1, 1, -1, -1, 2, -2, 2, -2};
const int dc[] = {2, -2, 2, -2, 1, 1, -1, -1};
int main(){
    int N, M;
    cin >> N >> M;

    pair <int, int> from, to;
    cin >> from.first >> from.second >> to.first >> to.second;

    from.first--; from.second--; to.first--; to.second--;
    priority_queue <tuple <int,  pair <int, int>>, vector<tuple <int,  pair <int, int>>>, greater<tuple <int,  pair <int, int>>>> q;
    vector <vector<int>> cost(N, vector<int> (M, 1e9));
    q.push({0, from});
    cost[from.first][from.second] = 0;

    while(!q.empty()){
        int cur_move;
        pair <int, int> cur_rc;

        tie(cur_move, cur_rc) = q.top(); q.pop();
        //if(cost[cur_rc.first][cur_rc.second] <= cur_move) continue;

        int next_move = cur_move+1;
        for(int i = 0; i < 8; i++){
            pair <int, int> new_rc;

            new_rc.first = cur_rc.first + dr[i];
            new_rc.second = cur_rc.second + dc[i];

            if(new_rc.first < 0 || new_rc.first >= N || new_rc.second < 0 || new_rc.second >= M) continue;
            if(cost[new_rc.first][new_rc.second] <= next_move) continue;

            cost[new_rc.first][new_rc.second] = next_move;

            q.push({next_move, new_rc});
        }
    }

    cout << cost[to.first][to.second];

    return 0;
}