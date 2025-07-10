#include <iostream>

using namespace std;

// 이항계수
// https://www.acmicpc.net/problem/11051
int map[1000+1][1000+1] = {0,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    map[0][0] = 1;
    map[1][0] = 1;
    map[1][1] = 1;
    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                map[i][j] = 1;
            }
            else{
                map[i][j] = (map[i-1][j-1] + map[i-1][j])%10007;
            } 
        }
    }

    cout << map[N][K];

    return 0;
}