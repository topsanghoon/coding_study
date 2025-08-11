#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, target;
    cin >> n >> target;

    vector<tuple<int, int, int, int>> results;
    tuple<int, int, int> target_medals;

    for (int i = 0; i < n; i++) {
        int country, gold, silver, bronze;
        cin >> country >> gold >> silver >> bronze;

        results.push_back({gold, silver, bronze, country});

        if (country == target) {
            target_medals = {gold, silver, bronze};
        }
    }

    // 금 > 은 > 동 내림차순 정렬
    sort(results.begin(), results.end(), [](const auto& a, const auto& b) {
        return tie(get<0>(a), get<1>(a), get<2>(a)) > tie(get<0>(b), get<1>(b), get<2>(b));
    });

    int rank = 1;
    for (const auto& [g, s, b, c] : results) {
        if (tie(g, s, b) == target_medals) {
            cout << rank << '\n';
            break;
        }
        rank++;
    }

    return 0;
}
