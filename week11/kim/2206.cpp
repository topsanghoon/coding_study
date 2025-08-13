#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<vector<int>> arr;
vector<vector<bool>> visited[2];

queue<tuple<int,int,int,int>> q;
int n,m;
int ny[4] = {1,-1,0,0};
int nx[4] = {0,0,1,-1};

int bfs(){
    q.push(make_tuple(0,0,0,1));
    visited[0][0][0] = true;

    while(!q.empty()){

        tuple<int,int,int,int> qfront = q.front();
        int cur_y = get<0>(qfront);
        int cur_x = get<1>(qfront);
        int cur_k = get<2>(qfront);
        int cur_d = get<3>(qfront);

        // cout << "cur_y: "<<cur_y;
        // cout << " cur_x: "<<cur_x;
        // cout << " cur_k: "<<cur_k;
        // cout << " cur_d: "<<cur_d<<'\n';

        q.pop();
        
        if(cur_y==n-1 && cur_x==m-1){
            return cur_d;
        }

        int next_y, next_x, next_k, next_d;
        next_d = cur_d+1;

        for(int i=0;i<4;i++){
            
            next_y = cur_y+ny[i];
            next_x = cur_x+nx[i];
            next_k = cur_k;

            if(!(0<=next_y && next_y<n)) continue;
            if(!(0<=next_x && next_x<m)) continue;
            if(arr[next_y][next_x]==1){
                if(next_k==1) continue;
                next_k = next_k+1;
            }
            cur_d = cur_d+1;

            if(visited[next_k][next_y][next_x]) continue;

            visited[next_k][next_y][next_x] = true;
            q.push(make_tuple(next_y, next_x, next_k, next_d));

        }

    }
    return -1;
}

int main(){


    cin >> n >> m;
    arr = vector<vector<int>>(n,vector<int>(m,0));
    for(int i=0;i<2;i++){
        visited[i] = vector<vector<bool>>(n,vector<bool>(m,false));
    }

    string str;
    for(int i=0;i<n;i++){
        cin >> str;
        for(int j=0;j<str.size();j++){
            arr[i][j] = (str[j]=='1' ? 1 : 0);
        }
    }

    cout << bfs();

    return 0;
}

