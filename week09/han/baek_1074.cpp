#include <iostream>
#include <cmath>
using namespace std;

// Z
// https://www.acmicpc.net/problem/1074

int divideAndConquer(int n, int goalR, int goalC){
    if(n==0) return 0;
    int mid = 1 << (n-1);

    if(goalR >= mid && goalC >= mid) return (4 - 1) * (mid * mid) + divideAndConquer(n-1, goalR-mid, goalC-mid); // 4분면
    else if(goalR >= mid && goalC < mid) return (3 - 1) * (mid * mid) + divideAndConquer(n-1, goalR - mid, goalC); // 3분면
    else if(goalR < mid && goalC >= mid) return (2 - 1) * (mid * mid) + divideAndConquer(n-1, goalR, goalC - mid);
    else if(goalR < mid && goalC < mid) return divideAndConquer(n - 1, goalR, goalC);
    return -1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, r, c;
    cin >> N >> r >> c;
    cout << divideAndConquer(N,r,c);
}