#include <iostream>
#include <cstdint>
using namespace std;

// 곱셈
// https://www.acmicpc.net/problem/1629
int fast_pow(int a, int b, int c){
    if(b == 0) return 1;
    if(b == 1) return a%c;
    int temp = fast_pow(a, b/2, c);
    int temp_squared = (1LL * temp * temp) % c;
    if(b%2 == 0) return temp_squared;
    else return 1LL * (a%c) * temp_squared % c;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;
    cout << fast_pow(A,B,C) % C << "\n";
}