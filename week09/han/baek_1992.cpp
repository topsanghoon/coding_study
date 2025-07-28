#include <iostream>

using namespace std;

// 쿼드트리
// https://www.acmicpc.net/problem/1992
int map[64+2][64+2] = {0,} ;
int N;
void divideAndConquer(int n, int x, int y){
    int sameFlag = true;
    int standard = map[x][y];

    for(int i = x; i < x + n && sameFlag; i++){
        for(int j = y; j < y + n; j++){
            if(standard != map[i][j]){
                sameFlag = false;
                break;
            }
        }
    }

    if(sameFlag) {
        cout << map[x][y];
        return;
    }

    cout << "(";
    int mid = n/2;
    divideAndConquer(mid, x, y); // 1사분면
    divideAndConquer(mid, x, y + mid); // 3
    divideAndConquer(mid, x + mid, y); // 2
    divideAndConquer(mid, x + mid, y + mid); // 4
    cout << ")";

}

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        string line;
        cin >> line;
        for(int j = 0; j < N; j++){
            map[i][j] = (int)(line[j]) - '0';
        }
    }

    // cout << "\n";
    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= N; j++){
    //         cout << map[i][j];
    //     }
    //     cout << "\n";
    // }

    divideAndConquer(N, 0, 0);
}