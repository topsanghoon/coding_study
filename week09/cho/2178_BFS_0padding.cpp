#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point{
    int x;
    int y;
    int count;
};

int main() {
    int N,M;
    cin>>N>>M;
    vector<vector<int>> map(N+2,vector<int>(M+2,0));
    //vector<vector<bool>> visited(N+1,vector<bool>(M+1,false));
    string tmp;
    for (int i=1; i<N+1;i++ ) {
        cin>>tmp;        
        for(int j=1;j<M+1;j++){
            map[i][j] = tmp[j-1] -'0';
        }
    }

    // for (int i=0; i<N+1;i++ ) {
    //     for(int j=0;j<M+1;j++){
    //         cout<<map[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    
    queue<Point> q;
    q.push({1,1,1});
    //visited[1][1]=true;
    map[1][1] = 0;
    int min_res=100000;
    while(!q.empty()){
        Point cur = q.front();
        q.pop();
        if(cur.x ==M && cur.y ==N){
            if(min_res > cur.count){
                min_res = cur.count;
                break;//최단거리 이기 때문에 먼저 도착하면 끝내도 됨. 
            }
        }
        for(int i=0;i<4;i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int count = cur.count;
            //if(nx<1 ||nx>M ||ny<1||ny>N) continue;
            if(map[ny][nx] ==0) continue;
            //if(visited[ny][nx]) continue;
            //visited[ny][nx] =true;
            q.push({nx,ny,count+1});
            map[ny][nx]=0;
            //cout<<"nx: "<<nx<<" "<<"ny: "<<ny<<"count: "<<count+1<<'\n';
        }
        
    }
    cout<<min_res;
    
    
    return 0;
}