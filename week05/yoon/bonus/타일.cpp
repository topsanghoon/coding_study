#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll maxY, maxX;
    ll n, m;
    cin >> maxY >> maxX >> n >> m;

    vector<ll> xs(m);
    ll y;
    ll low = 0;
    for(int i = 0; i < m; i++){
        cin >> y >> xs[i];
        low = max(low, y);
    }
    sort(xs.begin(), xs.end());

    ll high = maxX;
    auto needed = [&](ll k)->ll{
        if(k == 0) return (ll)1e18;
        ll cnt = 1;
        ll coverEnd = xs[0] + k - 1;
        for(int i = 1; i < m; i++){
            if(xs[i] > coverEnd){
                cnt++;
                coverEnd = xs[i] + k - 1;
            }
        }
        return cnt;
    };

    ll ans = high;
    while(low <= high){
        ll mid = (low + high) / 2;
        ll used = needed(mid);
        if(used <= n){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}