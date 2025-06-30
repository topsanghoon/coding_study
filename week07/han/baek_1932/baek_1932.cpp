#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/1932
// 정수 삼각형
int map[500+1][500+1][2] = {0,};
int main(void){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            cin >> map[i][j][0];
        }
    }
    
    map[1][1][1] += map[1][1][0];

    map[2][1][1] = map[1][1][1] + map[2][1][0];
    map[2][2][1] = map[1][1][1] + map[2][2][0];

    for(int i = 3; i <= N; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1){
                map[i][j][1] = map[i-1][j][1] + map[i][j][0];
            }
            else if(j == i){
                map[i][j][1] = map[i-1][j-1][1] + map[i][j][0];
            }
            else{
                map[i][j][1] = max(map[i-1][j-1][1],map[i-1][j][1]) + map[i][j][0]; 
            }
        }
    }
    int max = 0;
    for(int i = 1; i <= N; i++){
        if(max < map[N][i][1]){
            max = map[N][i][1];
        }
    }
    cout << max;
}