//곱셈
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

using ll = long long;

int main(){

    ll A, B, C;
    cin >> A >> B >> C;

    A  %= C;

    ll DP[63] = {0};
    DP[1] = A;
    for(int i = 2; i <= 62; i++){
        DP[i] = (DP[i - 1] * DP[i - 1]) % C;
        //cout << DP[i] << " ";
    }
    //cout << endl;

    ll answer = 1;
    int current_n = 63;
    ll current = 1LL << 62;
    while(B != 0){
        while(B - current >= 0){
            //cout << B << "    "  << current  << "    " << current_n << "  ";
            B -= current;
            answer = (answer * DP[current_n]) % C;
            //cout << answer  << endl;

        }
        current = current >> 1;
        current_n--;
    }

    cout << answer;
    

    return 0;
}