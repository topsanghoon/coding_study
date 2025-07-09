//벽장문 이동
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int L, N;
vector <int> wall_order(20);

vector <int> visited(20);
vector <int> selected(20);

int min_cnt = 1e9;
int moved;


tuple<bool, int, int, int> able_to_move(int door, int depth, int right_d, int left_d){
    int door_use = (door == 0) ? left_d : right_d;
    int door_else = (door == 0) ? right_d : left_d;
    int order = wall_order[depth];

    int left_side = min(door_use, order);
    int right_side = max(door_use, order);

    if (door_else >= left_side && door_else <= right_side)
        return {false, 0, left_d, right_d};  // 이동 불가능

    int moved = right_side - left_side;
    if (door == 0) left_d = order;
    else right_d = order;

    return {true, moved, left_d, right_d};  // 이동 가능
}

void dfs(int depth, int cnt_sum, int left_d, int right_d) {
    if (cnt_sum >= min_cnt) return;

    if (depth == N) {
        min_cnt = cnt_sum;
        return;
    }

    for (int next = 0; next < 2; ++next) {
        int ok, move_cost, new_left, new_right;
        tie(ok, move_cost, new_left, new_right) = able_to_move(next, depth, right_d, left_d);
        if (!ok) continue;

        dfs(depth + 1, cnt_sum + move_cost, new_left, new_right);
    }
}

int main() {
    int left_open, right_open;
    cin >> L; //벽장의 길이
    cin >> left_open >> right_open; //왼쪽 문 , 오른쪽 문
    cin >> N; // 문제 개수

    for(int i = 0; i < N; i++) {
        cin >> wall_order[i];
    }

    dfs(0, 0, left_open, right_open);//진행 횟수, 현재 위치, 총 합

    cout << min_cnt << "\n";
    return 0;
}
