#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> graph;
vector<bool> crossVisited;

vector<vector<pair<int,int>>> bsMap;
stack<pair<int,int>> debug;

int n;
int ans = 0;

void dfs(int idx, int cnt){

    if(idx+1==2*n){

        if(ans < cnt){

            // stack<pair<int,int>> buf;
            // while(!debug.empty()){
            //     buf.push(debug.top());
            //     cout << debug.top().first << " " << debug.top().second << '\n';
            //     debug.pop();
            // }
            // while(!buf.empty()){
            //     debug.push(buf.top());
            //     buf.pop();
            // }
            // cout << "\n-----------\n";
        }
        ans = max(ans,cnt);
        return ;

    }

    bool flag = false;
    for(pair<int,int> point : bsMap[idx]){
        int y = point.first;
        int x = point.second;

        if(crossVisited[y-x+n]) continue;

        crossVisited[y-x+n] = true;
        //debug.push(make_pair(y,x));
        dfs(idx+1, cnt+1);
        flag = true;
        //debug.pop();
        crossVisited[y-x+n] = false;

    }
    if(!flag){
        dfs(idx+1,cnt);
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;

    graph = vector<vector<int>>(n,vector<int>(n,0));
    crossVisited = vector<bool>(2*n,false);
    bsMap = vector<vector<pair<int,int>>>(2*n, vector<pair<int,int>>());

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];

            if(graph[i][j]==1){
                bsMap[i+j].push_back(make_pair(i,j));
            }
        }
    }

    dfs(0,0);
    cout << ans;
    return 0;
}