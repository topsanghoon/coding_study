#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector <int> susi;

    for(int i =0; i < n; i++){
        int temp;
        cin >> temp;
        susi.push_back(temp);
    }

    int max_n = 0;
    for(int i = 0; i < n; i++){
        vector <int> susi_map(d+1, 0);
        int cnt = 0;
        for(int j = 0; j < k; j++){
            if(susi_map[susi[(i+j)%n]] == 0){
                susi_map[susi[(i+j)%n]]++;
                cnt++;
            }
        }
        if(susi_map[c] == 0) cnt++;

        max_n = max(cnt, max_n);
    }

    cout << max_n;

    return 0;
}

