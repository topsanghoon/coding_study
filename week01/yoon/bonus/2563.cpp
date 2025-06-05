#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector <vector <int>> map(100, vector <int> (100, 0));

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
            if(map[i][j]) cnt++;
        }
    }

    cout << cnt;
}