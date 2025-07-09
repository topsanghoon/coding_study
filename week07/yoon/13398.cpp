#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> deleted(n); // 삭제 없이
    vector<int> not_deleted(n);    // 하나 삭제한 상태

    deleted[0] = arr[0];
    not_deleted[0] = arr[0];
    int ans = arr[0];

    for (int i = 1; i < n; i++) {
        //삭제 안한 경우 : 이전까지 합 + 현재값 or 현재값
        deleted[i] = max(deleted[i - 1] + arr[i], arr[i]); 

        // 삭제한 경우 : 이전 삭제한 상태 + 현재값 or 이전까지 안지운 최대에서 현재거 지운 값
        not_deleted[i] = max(not_deleted[i - 1] + arr[i], deleted[i - 1]); 
        ans = max({ans, deleted[i], not_deleted[i]});
    }

    cout << ans << '\n';
    return 0;
}
