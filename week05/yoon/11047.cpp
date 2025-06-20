#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    vector <int> bills(n);
    for(int i = n-1; i >= 0; i--){
        cin >> bills[i];
    }

    int cnt = 0;

    // for(int i = 0; i > n; i++){
    //     cout << bills[i];
    // }

    for(int i = 0; i < n; i++){
        if(k == 0) break;
        if(k / bills[i] > 0) {
            cnt = cnt + k / bills[i];
            k = k % bills[i];
        }
    }

    cout << cnt;

    return 0;
}