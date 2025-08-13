#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int is_zero = 0;

void rotate_belt_and_robots(int &UP, int &DOWN, int n, vector<int> &Robots) {
    int m = 2 * n;
    UP   = (UP   - 1 + m) % m;
    DOWN = (DOWN - 1 + m) % m;

    // for (int &pos : Robots) {
    //     pos = (pos - 1 + m) % m;
    // }

    // 회전 후 가장 오래된 로봇이 DOWN에 있으면 바로 내림
    if (!Robots.empty() && Robots.front() == DOWN) {
        Robots.erase(Robots.begin());
    }
}

void move_robots(vector<int> &Robots, vector<int> &Belt, int DOWN, int n) {
    int m = 2 * n;
    vector<bool> occ(m, false);
    for (int pos : Robots) occ[pos] = true;

    for (int i = 0; i < (int)Robots.size(); i++) {
        int cur  = Robots[i];
        int next = (cur + 1) % m;

        if (!occ[next] && Belt[next] > 0) {
            occ[cur] = false;
            occ[next] = true;
            Robots[i] = next;
            Belt[next]--;
            if (Belt[next] == 0) is_zero++;
        }
    }

    // 이동 후 오래된 로봇이 DOWN에 있으면 제거
    if (!Robots.empty() && Robots.front() == DOWN) {
        Robots.erase(Robots.begin());
    }
}

void put_robot(vector<int> &Robots, vector<int> &Belt, int UP, int DOWN) {
    vector<bool> occ(Belt.size(), false);
    for (int pos : Robots) occ[pos] = true;

    if (!occ[UP] && Belt[UP] > 0) {
        Robots.push_back(UP);
        Belt[UP]--;
        if (Belt[UP] == 0) is_zero++;
    }

    // 올린 즉시 DOWN이면 제거
    if (!Robots.empty() && Robots.front() == DOWN) {
        Robots.erase(Robots.begin());
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> Belt(2 * N);
    for (int &dur : Belt) {
        cin >> dur;
        if (dur == 0) is_zero++;
    }

    vector<int> Robots;
    int UP = 0, DOWN = N - 1;
    int step = 0;

    while (is_zero < K) {
        rotate_belt_and_robots(UP, DOWN, N, Robots);
        move_robots(Robots, Belt, DOWN, N);
        put_robot(Robots, Belt, UP, DOWN);
        step++;
    }

    cout << step << '\n';
    return 0;
}
