#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

struct Pos { int r, c; };
struct State { int rr, rc, br, bc, d; };

int N, M;
vector<string> board;
Pos R, B, Hole;

const int dr[4] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
const int dc[4] = { 0, 0,-1, 1};

struct RollResult {
    Pos p;
    int moved;
    bool fell;
};

RollResult roll(Pos s, int dir) {
    Pos cur = s;
    int moved = 0;
    bool fell = false;
    while (true) {
        int nr = cur.r + dr[dir];
        int nc = cur.c + dc[dir];
        char cell = board[nr][nc];
        if (cell == '#') break;
        cur = {nr, nc};
        moved++;
        if (cell == 'O') {
            fell = true;
            break;
        }
    }
    return {cur, moved, fell};
}

tuple<Pos, Pos, bool, bool> tilt(Pos r0, Pos b0, int dir) {
    RollResult rr = roll(r0, dir);
    RollResult bb = roll(b0, dir);

    if (!rr.fell && !bb.fell && rr.p.r == bb.p.r && rr.p.c == bb.p.c) {
        if (rr.moved > bb.moved) {
            rr.p.r -= dr[dir];
            rr.p.c -= dc[dir];
        } else {
            bb.p.r -= dr[dir];
            bb.p.c -= dc[dir];
        }
    }
    return {rr.p, bb.p, rr.fell, bb.fell};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    board.resize(N);
    for (int i = 0; i < N; ++i) cin >> board[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 'R') { R = {i, j}; board[i][j] = '.'; }
            else if (board[i][j] == 'B') { B = {i, j}; board[i][j] = '.'; }
            else if (board[i][j] == 'O') { Hole = {i, j}; } // 'O' 유지
        }
    }

    static bool visited[10][10][10][10] = {false};
    queue<State> q;
    visited[R.r][R.c][B.r][B.c] = true;
    q.push({R.r, R.c, B.r, B.c, 0});

    while (!q.empty()) {
        auto [rr, rc, br, bc, d] = q.front(); q.pop();
        if (d >= 10) continue;

        for (int dir = 0; dir < 4; ++dir) {
            auto [r1, b1, rFell, bFell] = tilt({rr, rc}, {br, bc}, dir);

            if (rFell && bFell) continue;
            if (bFell) continue;

            if (rFell && !bFell) {
                cout << 1 << "\n";
                return 0;
            }

            if (r1.r == rr && r1.c == rc && b1.r == br && b1.c == bc) continue;

            if (!visited[r1.r][r1.c][b1.r][b1.c]) {
                visited[r1.r][r1.c][b1.r][b1.c] = true;
                q.push({r1.r, r1.c, b1.r, b1.c, d + 1});
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}
