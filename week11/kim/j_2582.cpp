#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int getSum(int mx){ // 시간복잡도 ~ 10000
    int sum = 0;
    for(int ele : arr){
        sum += (ele < mx) ? ele : mx;
    }
    return sum;
}

int main(){

    int n;
    cin >> n;
    arr = vector<int>(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int m;
    cin >> m;

    int s = 0;
    int e = 0;

    for(int i=0;i<n;i++){
        e = max(e,arr[i]);
    }

    if(getSum(e) < m){
        cout << e << '\n';
        return 0;
    }

    int mid;
    int ans = 0;

    while(s<=e){ // log1000000000
        mid = (s+e)/2;
        if(getSum(mid) <= m){
            s = mid-1;
            ans = mid;
        } else {
            e = mid-1;
        }
    }

    cout << ans << '\n';

    return 0;
}