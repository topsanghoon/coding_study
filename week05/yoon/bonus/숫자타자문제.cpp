#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Pos {
    int r, c;
};

Pos keypad[10] = {
    {3, 1}, {0, 0}, {0, 1}, {0, 2},
    {1, 0}, {1, 1}, {1, 2},
    {2, 0}, {2, 1}, {2, 2}
};

int cost_table[10][10][10];

int moveCost(Pos from, Pos to) {
    if (from.r == to.r && from.c == to.c) return 1;
    int dr = abs(from.r - to.r);
    int dc = abs(from.c - to.c);
    return min(dr, dc) * 3 + abs(dr - dc) * 2;
}

void precompute_costs() {
    for (int l = 0; l < 10; ++l) {
        for (int r = 0; r < 10; ++r) {
            for (int num = 0; num < 10; ++num) {
                int leftCost = moveCost(keypad[l], keypad[num]);
                int rightCost = moveCost(keypad[r], keypad[num]);
                cost_table[l][r][num] = min(leftCost, rightCost);
            }
        }
    }
}

int solution(string numbers) {
    precompute_costs();

    int total = 0;
    int left = 4;   // '*' 위치 대신 4 (1, 0)
    int right = 6;  // '#' 위치 대신 6 (1, 2)

    for (char ch : numbers) {
        int num = ch - '0';
        int leftCost = moveCost(keypad[left], keypad[num]);
        int rightCost = moveCost(keypad[right], keypad[num]);

        total += cost_table[left][right][num];

        if (leftCost <= rightCost) {
            left = num;
        } else {
            right = num;
        }
    }

    return total;
}
