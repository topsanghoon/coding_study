//단지 번호 붙히기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector <string> map;
vector <vector<bool>> visited;
int n = 0;

const int dir_x[4] = {1, -1 , 0, 0};
const int dir_y[4] = {0, 0 , 1, -1};
int search(int x, int y, int cnt){

    //bool have_more = false;
    for(int i = 0; i < 4; i++){
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 밖이면 패스

        if(visited[nx][ny] == true) continue;
        if(map[nx][ny] == '0'){ //아닌 곳은 패스
            visited[nx][ny] = true;
            continue;
        }
        //have_more = true;
        visited[nx][ny] = true;
        cnt = search(nx, ny, cnt + 1);
    }

    return cnt;
}

int main(){
    cin >> n;
    
    visited.resize(n);
    for(int i = 0; i < n; i++){
        visited[i].resize(n, false);
    }

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        map.push_back(temp);
    }
    
    vector <int> results;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
            if(visited[i][j] == true) continue;
            if(map[i][j] == '0') {
                visited[i][j] = true; 
                continue;
            }
            visited[i][j] = true; 
            results.push_back(search(i, j, 1));
        }
    }

    sort(results.begin(), results.end());

    cout << results.size() << "\n";
    for(int result : results) cout << result << "\n";

    return 0;
}