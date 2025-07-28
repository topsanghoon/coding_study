#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

const int dr[] = {0, 0, -1, 1};
const int dc[] = {-1, 1, 0, 0};

int main() {
    int n;
    cin >> n;

    int max_height = 0;
    vector<vector<int>> ground(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ground[i][j];
            max_height = max(max_height, ground[i][j]);
        }
    }

    int max_safe_area = 0;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    int visit_mark = 1;

    for (int rain = 0; rain <= max_height; rain++) {
        int safe_area_count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == visit_mark) continue;
                if (ground[i][j] <= rain) continue;

                queue<tuple<int, int>> q;
                q.push({i, j});
                visited[i][j] = visit_mark;
                safe_area_count++;

                while (!q.empty()) {
                    int cr, cc;
                    tie(cr, cc) = q.front(); q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nr = cr + dr[d];
                        int nc = cc + dc[d];
                        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                        if (ground[nr][nc] <= rain) continue;
                        if (visited[nr][nc] == visit_mark) continue;

                        visited[nr][nc] = visit_mark;
                        q.push({nr, nc});
                    }
                }
            }
        }

        max_safe_area = max(max_safe_area, safe_area_count);
        visit_mark++;
    }

    cout << max_safe_area;
    return 0;
}
