#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int start){
    visited[start] = true;

    for(int i=0;i<graph[start].size();i++){
        int next = graph[start][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}


int main(){

    int n;
    cin >> n;

    if(n==1){
        cout << 0;
        return 0;
    }

    int edge_cnt = 0;
    int group_cnt = 0;
    graph = vector<vector<int>>(n,vector<int>());
    visited = vector<bool>(n,false);

    string str;

    bool flag = false;
    for(int i=0;i<n;i++){
        cin >> str;
        flag = false;
        for(int j=0;j<n;j++){
            if(str[j]=='Y'){
                graph[i].push_back(j);
                edge_cnt++;
                flag = true;
            }
        }
        if(!flag){
            cout << -1 << '\n';
            return 0;
        }
    }
    edge_cnt/=2;
    if(edge_cnt < n-1){
        cout << -1 << '\n';
        return 0;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            group_cnt++;
        }
    }

    cout << group_cnt-1 << '\n';

    return 0;
}