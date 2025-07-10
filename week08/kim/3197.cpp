#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<vector<char>> arr;
vector<vector<int>> ice_map;
vector<vector<int>> find_map;

queue<pair<int,int>> q;
vector<pair<int,int>> flag;
int n,m;
int ny[4] = {1,-1,0,0};
int nx[4] = {0,0,1,-1};

void bfs();
void bfs(){ // 얼음맵 생성성
    while(!q.empty()){
        pair<int,int> qfront = q.front();
        q.pop();

        int nexty, nextx;
        for(int i=0;i<4;i++){
            nexty = qfront.first+ny[i];
            nextx = qfront.second+nx[i];

            if(!(0<=nexty && nexty<n)) continue;
            if(!(0<=nextx && nextx<m)) continue;
            if(arr[nexty][nextx]!='X') continue;
            if(ice_map[nexty][nextx]!=0) continue;

            ice_map[nexty][nextx] = ice_map[qfront.first][qfront.second]+1;
            q.push(make_pair(nexty,nextx));
        }
        
    }
}
void bfs_findroute(){
    while(!q.empty()){
        pair<int,int> qfront = q.front();
        q.pop();

        int nexty, nextx, next_cost;
        for(int i=0;i<4;i++){
            nexty = qfront.first+ny[i];
            nextx = qfront.second+nx[i];
            
            if(!(0<=nexty && nexty<n)) continue;
            if(!(0<=nextx && nextx<m)) continue;
            
            next_cost = max(find_map[qfront.first][qfront.second]
                ,ice_map[nexty][nextx]); 
            
            if(find_map[nexty][nextx] <= next_cost) continue;

            find_map[nexty][nextx] = next_cost;
            q.push(make_pair(nexty,nextx));
        }
        
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;

    arr = vector<vector<char>>(n,vector<char>(m,0));
    ice_map = vector<vector<int>>(n,vector<int>(m,0));
    find_map = vector<vector<int>>(n,vector<int>(m,2147483647));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.'){
                q.push(make_pair(i,j));
            }
            if(arr[i][j]=='L'){
                q.push(make_pair(i,j));
                flag.push_back(make_pair(i,j));
            }
        }
    }

    bfs();

    q.push(flag[0]);
    find_map[flag[0].first][flag[0].second]=0;
    
    bfs_findroute();



    cout << find_map[flag[1].first][flag[1].second];
    
    return 0;
}