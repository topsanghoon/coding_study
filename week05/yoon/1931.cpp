#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > time_list;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        time_list.push({end, start}); // 끝나는 시간 기준 정렬
    }

    int cnt = 0;
    int end_time = 0;

    while (!time_list.empty()) {
        int cur_end = time_list.top().first;
        int cur_start = time_list.top().second;
        time_list.pop();

        if (cur_start >= end_time) {
            cnt++;
            end_time = cur_end;
        }
    }

    cout << cnt << '\n';
    return 0;
}
