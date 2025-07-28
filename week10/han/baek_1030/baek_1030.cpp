#include <iostream>
#include <cmath>
using namespace std;

// 프렉탈 평면
// https://www.acmicpc.net/problem/1030
int s, N, K, R1, R2, C1, C2;

void printPrectal(int time, int x, int y){
    
    // int row = x % N;
    // int column = y % N;

    int blockSize = 1;
    if(time != 0) blockSize = pow(N,time-1);

    // int row = x / blockSize;
    // int column = y / blockSize;
    
    int row = x / blockSize % N;
    int column = y / blockSize % N;
    
    int start = (N - K) / 2;
    int end = start + K;

    if (row >= start && row < end && column >= start && column < end) {
        cout << 1;
        return;
    }
    else{
        if(time == s) cout << 0;
        else printPrectal(time + 1, x, y);
    }
}

int main(void){
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
    for(int i = R1; i <= R2; i++){
        for(int j = C1; j <= C2; j++){
            printPrectal(0, i, j);
        }
        cout << "\n";
    }
}