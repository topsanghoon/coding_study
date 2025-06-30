#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/2579
// 계단오르기
int dpArr[301][3] = {0,}; // dpArr[i][1]: 한 번에 온 경우(2칸 점프), dpArr[i][2]: 한 칸씩 두 번 온 경우
int score[301] = {0,};
int main(void){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> score[i];
    }
    dpArr[1][1] = score[1];
    dpArr[1][2] = 0;
    dpArr[2][1] = score[2];
    dpArr[2][2] = dpArr[1][1] + score[2];

    for(int i = 3; i <= N; i++){
        dpArr[i][1] = max(dpArr[i-2][1], dpArr[i-2][2]) + score[i];
        dpArr[i][2] = dpArr[i-1][1] + score[i]; 
    }
    cout << max(dpArr[N][1],dpArr[N][2]);
}