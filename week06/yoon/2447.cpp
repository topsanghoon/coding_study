#include <iostream>
#include <vector>

using namespace std;

int n = 0;
vector<vector<bool>> star_map;

void copy_star(int num, int r, int c){  //복사하는 함수
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            star_map[r + i][c + j] = star_map[i][j];
        }
    }
    return;
}


void get_map(int num){  //이전에 만들어진 형태를 복사해서 나머지 칸에 붙혀넣음
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if((i == 0 && j == 0) || (i == 1 && j == 1)) continue;;
            copy_star(num, i*num, j*num);
        }
    }
    if(num * 3 == n) return;
    get_map(num*3);
    return;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    star_map.resize(n);
    for(int i =0; i < n; i++) star_map[i].resize(n);

    #ifndef ONLINE_JUDGE
    cout << "come here";
    #endif


    for(int i = 0; i < 3; i++){       //초기 생성
        for(int j = 0; j < 3; j++){
            star_map[i][j] = true;
        }
    }
    star_map[1][1] = false;
    if(n != 3) get_map(3);

    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(star_map[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << "\n";
    }

    return 0;
}