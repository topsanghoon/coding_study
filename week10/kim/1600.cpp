#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct Node {
    int y;
    int x;
    int depth;
    int k_cnt;
};

vector<vector<int>> arr;
vector<vector<bool>> visited[31];
queue<Node> q; // (y,x,depth,k_count) 저장

int k,n,m;;

int ny[12] = {1,-1,0,0,1,2,2,1,-1,-2,-2,-1}; // 4부터는 말 이동, 이전에는 원숭이 이동
int nx[12] = {0,0,1,-1,-2,-1,1,2,2,1,-1,-2};

int bfs(){
    q.push(Node{0,0,0,0});

    while(!q.empty()){
        Node qf = q.front();
        
        if(qf.y==m-1 && qf.x==n-1){
            return qf.depth;
        }

        q.pop();

        // cout<<qf.y<<" ";
        // cout<<qf.x<<" ";
        // cout<<qf.depth<<" ";
        // cout<<qf.k_cnt<<" ";
        // cout<<endl;

        int nexty,nextx,next_depth,k_cnt, next_k_cnt;
        for(int i=0;i<12;i++){
            
            nexty = qf.y+ny[i];
            nextx = qf.x+nx[i];
            next_depth = qf.depth+1;
            k_cnt = qf.k_cnt;

            //cout <<k_cnt<<" "<<nexty<<" "<<nextx<<endl;

            if(!(0<=nexty && nexty<m)) continue;
            if(!(0<=nextx && nextx<n)) continue;
            if(arr[nexty][nextx]==1) continue;
            if(i>=4 && k_cnt>=k) break; // 말처럼 이동 하려는데 횟수를 다 쓰면

            next_k_cnt = (i>=4) ? k_cnt+1 : k_cnt;
            if(visited[next_k_cnt][nexty][nextx]) continue;

            visited[next_k_cnt][nexty][nextx] = true;
            q.push(Node{nexty,nextx,next_depth,next_k_cnt});
        }

    }
    return -1;
}// 4 0 2
int main(){

    cin >> k;


    cin >> n >> m;

    arr = vector<vector<int>>(m,vector<int>(n,-1));
    for(int i=0;i<=k;i++){
        visited[i] = vector<vector<bool>>(m,vector<bool>(n,false));
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    cout<<bfs();

    return 0;
}