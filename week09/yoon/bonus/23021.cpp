#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;
using ll = long long;

int T;
ll fact[20];

// 팩토리얼 전처리
void init_factorial() {
    fact[0] = 1;
    for (int i = 1; i <= 18; ++i)
        fact[i] = (fact[i - 1] * i) % MOD;
}

// (선택한 개수, 합)을 모두 구해서 bucket[k]에 sum만 넣기
vector<vector<ll>> make_partial_sums(const vector<int>& arr) {
    int n = arr.size();
    vector<vector<ll>> bucket(n + 1);  // bucket[k] = 합 리스트

    for (int mask = 1; mask < (1 << n); ++mask) {
        int k = __builtin_popcount(mask);
        ll sum = 0;
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i)) sum += arr[i];
        bucket[k].push_back(sum);
    }

    for (int k = 1; k <= n; ++k)
        sort(bucket[k].begin(), bucket[k].end());

    return bucket;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init_factorial();

    cin >> T;
    while (T--) {
        int n, m;
        ll x, C, D;
        cin >> n >> m >> x >> C >> D;

        vector<int> A(n), B(m);
        for (int& a : A) cin >> a;
        for (int& b : B) cin >> b;

        // 부분합 구하기
        vector<vector<ll>> A_sum = make_partial_sums(A);
        vector<vector<ll>> B_sum = make_partial_sums(B);

        // cout << "[EAST mountain]\n";
        // for (int k = 1; k <= n; ++k) {
        //     cout << "k = " << k << " : ";
        //     for (ll sum : A_sum[k])
        //         cout << sum << " ";
        //     cout << '\n';
        // }

        // cout << "[WEST mountain]\n";
        // for (int k = 1; k <= m; ++k) {
        //     cout << "k = " << k << " : ";
        //     for (ll sum : B_sum[k])
        //         cout << sum << " ";
        //     cout << '\n';
        // }
        
        ll ans = 0;
        // cout << "[Search List]\n";
        for (int k = 1; k <= n; ++k) {
            for (ll sumA : A_sum[k]) {
                // cout << "\nA(k=" << k << ", sum=" << sumA << ")\n";
                for (int d = -1; d <= 1; ++d) {
                    int kb = k + d;
                    if (kb < 1 || kb > m) continue;

                    ll bridge = x * (k + kb - 1);
                    ll low = C - sumA - bridge;
                    ll high = D - sumA - bridge;

                    auto& b_list = B_sum[kb];
                    auto l = lower_bound(b_list.begin(), b_list.end(), low);
                    auto r = upper_bound(b_list.begin(), b_list.end(), high);
                    ll count = r - l;

                    // cout << "  B(k=" << kb << "), bridge=" << bridge
                    //     << ", sumB in [" << low << ", " << high << "] -> count = " << count << '\n';

                    ll ways = count % MOD;
                    ways = ways * fact[k] % MOD;
                    ways = ways * fact[kb] % MOD;
                    if (k == kb) ways = ways * 2 % MOD;

                    ans = (ans + ways) % MOD;
                }
            }
        }

        for (int a : A)
            if (C <= a && a <= D) ans = (ans + 1) % MOD;

        for (int b : B)
            if (C <= b && b <= D) ans = (ans + 1) % MOD;

    
        cout << ans << '\n';
    }

    return 0;
}
