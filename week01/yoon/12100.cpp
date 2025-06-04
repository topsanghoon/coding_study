#include <iostream>
#include <vector>

using namespace std;

const int dirc_x[4] = {1, 0, -1, 0};
const int dirc_y[4] = {0, 1, 0, -1};

int map_action(vector <vector <int>> map, int cnt, int max_n, int dirc){
    if(cnt == 5) return max_n;



    cnt++;
    map_action(map, cnt, max_n);
}

int main(){

    int n = 0, try_num = 5;
    cin >> n;

    vector <vector <int>> map(n, vector <int> (n, 0));

    for(int i =0; i<n; i++){        //맵 초기화화
        for(int j =0; j<n; j++){
            int temp = 0;
            cin >> temp;
            map[i][j] = temp;
        }
    }

    

    return 0;
}