//https://www.acmicpc.net/problem/20058

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, Q;
int N_size;
vector<vector<int>> arr;
vector<vector<int>> visited;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};

struct node {
    int x, y;
};

void map_rotation(int cur_row, int cur_col, int L_size) {
    vector<vector<int>> tmp(L_size, vector<int>(L_size));
    for (int i = 0; i < L_size; i++) {
        for (int j = 0; j < L_size; j++) {
            tmp[j][L_size - 1 - i] = arr[cur_row + i][cur_col + j];
        }
    }
    for (int i = 0; i < L_size; i++) {
        for (int j = 0; j < L_size; j++) {
            arr[cur_row + i][cur_col + j] = tmp[i][j];
        }
    }
}

void split(int L) {
    int len = 1 << L;
    for (int i = 1; i <= N_size; i += len) {
        for (int j = 1; j <= N_size; j += len) {
            map_rotation(i, j, len);
        }
    }
}

void check_ice() {
    vector<vector<int>> next_arr = arr;
    for (int i = 1; i <= N_size; i++) {
        for (int j = 1; j <= N_size; j++) {
            int cnt = 0;
            if (arr[i - 1][j] > 0) cnt++;
            if (arr[i + 1][j] > 0) cnt++;
            if (arr[i][j - 1] > 0) cnt++;
            if (arr[i][j + 1] > 0) cnt++;
            if (cnt < 3 && arr[i][j] > 0) next_arr[i][j]--;
        }
    }
    arr = next_arr;
}

int sum_ice() {
    int total = 0;
    for (int i = 1; i <= N_size; i++) {
        for (int j = 1; j <= N_size; j++) {
            if (arr[i][j] > 0)
                total += arr[i][j];
        }
    }
    return total;
}

int BFS_ice(int start_row, int start_col) {
    if (visited[start_row][start_col] || arr[start_row][start_col] <= 0)
        return 0;

    queue<node> q;
    q.push({start_row, start_col});
    visited[start_row][start_col] = 1;
    int ice_block = 0;

    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        ice_block++;

        for (int i = 0; i < 4; i++) {
            int nr = cur.x + drow[i];
            int nc = cur.y + dcol[i];

            if (nr < 1 || nr > N_size || nc < 1 || nc > N_size) continue;
            if (visited[nr][nc]) continue;
            if (arr[nr][nc] <= 0) continue;

            visited[nr][nc] = 1;
            q.push({nr, nc});
        }
    }
    return ice_block;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    N_size = 1 << N;
    arr.resize(N_size + 2, vector<int>(N_size + 2, 0));
    visited.resize(N_size + 2, vector<int>(N_size + 2, 0));

    for (int i = 1; i <= N_size; i++)
        for (int j = 1; j <= N_size; j++)
            cin >> arr[i][j];

    for (int i = 0; i < Q; i++) {
        int L;
        cin >> L;
        if (L > 0)
            split(L);
        check_ice();
    }

    int max_ice_block = 0;
    visited.assign(N_size + 2, vector<int>(N_size + 2, 0));

    for (int i = 1; i <= N_size; i++) {
        for (int j = 1; j <= N_size; j++) {
            if (arr[i][j] > 0 && !visited[i][j]) {
                int size = BFS_ice(i, j);
                if (size > max_ice_block)
                    max_ice_block = size;
            }
        }
    }

    cout << sum_ice() << '\n';
    cout << max_ice_block;

    return 0;
}
