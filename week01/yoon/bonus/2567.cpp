#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> map(100, vector <int> (100, 0));

const int dir_x[4] = {1, 0, -1, 0};
const int dir_y[4] = {0, 1, 0, -1};
int is_outside(int x, int y){
    int outside = 0;

    for(int i = 0; i < 4; i++){
        int nx, ny;
        nx = x + dir_x[i];
        ny = y + dir_y[i];

        if(nx > 99 || nx < 0 || ny > 99 || nx < 0 || !map[nx][ny]){
            outside++;
        }
    }

    return outside;
}

int main(){
    int n = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x_dif, y_dif = 0;
        cin >> x_dif >> y_dif;

        for(int i = x_dif; i < x_dif + 10; i++){
            for(int j = y_dif; j < y_dif + 10; j++){
                if(!map[i][j]) map[i][j] = 1;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(map[i][j]){
                int n = is_outside(i, j);
                if(n) cnt += n;
            }
        }
    }

    cout << cnt;
}