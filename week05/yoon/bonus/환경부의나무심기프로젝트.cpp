#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool canPlaceTrees(const vector<int>& point, int C, int d) {
    int count = 1;
    int last = point[0];

    for (int i = 1; i < point.size(); i++) {
        if (point[i] - last >= d) {
            count++;
            last = point[i];
        }
    }
    return count >= C;
}

int main(){

    int N, C;
    cin >> N >> C;

    vector <int> point(N);
    for(int i = 0; i < N; i++){
        cin >> point[i];
    }

    sort(point.begin(), point.end());

    int low = 1;
    int high = point[N-1] - point[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPlaceTrees(point, C, mid)) {
            ans = mid;          // 가능하면 저장하고 더 큰 간격 시도
            low = mid + 1;
        } else {
            high = mid - 1;     // 불가능하니 더 작은 간격 시도
        }
    }

    cout << ans;

    return 0;
}