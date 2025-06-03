//21:42 => 23:05
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);   

    int n, m;
    cin >> n >> m;

    vector<int> count(m, 0);
    count[0] = 1; 

    long long sum = 0;
    long long result = 0;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;

        sum = (sum + temp) % m;
        result += count[sum];  //누적하면서 진행
        count[sum]++;
    }

    cout << result << '\n';
    return 0;
}

/*
long long comb2(long long n) {
    return n * (n - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> count(m, 0);
    long long sum = 0;
    count[0] = 1;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        sum = (sum + temp) % m;
        count[sum]++;
    }

    long long result = 0;
    for (int i = 0; i < m; i++) {
        if (count[i] >= 2) {
            result += comb2(count[i]);
        }
    }

    cout << result;
    return 0;
}
*/