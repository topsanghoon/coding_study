#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

// 등산로 조합 (k개 선택했을 때의 가능한 길이 목록)
vector<vector<ll>> get_combinations(const vector<ll>& arr, ll x) {
    int n = arr.size();
    vector<vector<ll>> result(n + 1);

    for (int mask = 1; mask < (1 << n); ++mask) {
        ll sum = 0;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += arr[i];
                k++;
            }
        }
        sum += x * (k - 1); // 다리 길이 추가
        result[k].push_back(sum);
    }

    for (int i = 1; i <= n; ++i) {
        sort(result[i].begin(), result[i].end());
    }

    return result;
}

int count_plans(int n, int m, ll x, ll C, ll D, const vector<ll>& A, const vector<ll>& B) {
    auto A_comb = get_combinations(A, x);
    auto B_comb = get_combinations(B, x);
    int max_k = min(n, m);
    ll total = 0;

    for (int k = 1; k <= max_k; ++k) {
        const vector<ll>& A_list = A_comb[k];
        const vector<ll>& B_list = B_comb[k];

        for (ll a : A_list) {
            ll low = C - a;
            ll high = D - a;

            auto l = lower_bound(B_list.begin(), B_list.end(), low);
            auto r = upper_bound(B_list.begin(), B_list.end(), high);
            total = (total + (r - l)) % MOD;
        }
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        ll x, C, D;
        cin >> n >> m >> x >> C >> D;

        vector<ll> A(n), B(m);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < m; ++i) cin >> B[i];

        cout << count_plans(n, m, x, C, D, A, B) << "\n";
    }

    return 0;
}
