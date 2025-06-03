//21:00 21:41
#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);   

    int n = 0, m = 0;
    cin >> n >> m;

    vector <vector <int>> map(n+1, vector<int> (n+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int temp = 0;
            cin >> temp;
            int sum = temp + map[i][j-1];
            map[i][j] = sum;
        }
    }


    while(m--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int sum = 0;
        for(int h = x1; h <= x2; h++){
            sum += (map[h][y2]-map[h][y1-1]);
        }

        cout << sum << "\n";
    }

    return 0;
}