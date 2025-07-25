#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> entries;
vector<int> answer;
vector<bool> visited;
int main(){

    int v,e;
    cin >> v >> e;

    
    graph = vector<vector<int>>(v+1,vector<int>());
    entries = vector<int>(v+1,0);
    answer = vector<int>(v,0);
    visited = vector<bool>(v+1,0);
    int s,ed;
    for(int i=0;i<ed;i++){
        cin >> s >> ed;
        graph[s].push_back(ed);
        entries[ed]++;
    }

    queue<int> q;

    // for(int i=1;i<=v;i++){
    //     cout<<"i: ";
    //     for(int j=0;j<graph[i].size();j++){
    //         cout<<graph[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    
    for(int i=1;i<=v;i++){
        if(entries[i]==0){
            visited[i] = true;
            q.push(i);
        }
    }
    int idx = 0;

    while(!q.empty()){
        int qf = q.front();
        q.pop();
        answer[idx++] = qf;

        for(int nd : graph[qf]){
            entries[nd]--;
            if(entries[nd]==0 && !visited[nd]){
                q.push(nd);
                visited[nd] = true;
            }
        }
    }

    for(int n : answer){
        cout << n << " ";
    }

    return 0;
}