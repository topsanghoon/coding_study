#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> nodeStatus;
vector<bool> visited;
queue<int> q;

bool bfs(int i)
{
    q.push(i);
    visited[i] = true;

    while(!q.empty()){
        int qfront = q.front();
        q.pop();

        for(int i=0;i<graph[qfront].size();i++){
            int next = graph[qfront][i];
            bool newStatus = !nodeStatus[qfront];
            if(visited[next] && nodeStatus[next]!=newStatus){
                return false;
            }
            if(visited[next]){
                continue;
            }

            visited[next] = true;
            nodeStatus[next] = newStatus;
            q.push(next);
        }


    }
    return true;
}

void execute()
{

    int e,v;
    cin >> e >> v;
    graph = vector<vector<int>>(e+1);
    nodeStatus = vector<bool>(e+1,false);
    visited = vector<bool>(e+1,false);

    int st,ed;
    for(int i=0; i<v ;i++){
        cin >> st >> ed;
        graph[st].push_back(ed);
        graph[ed].push_back(st);
        
    }
    bool ans = true;
    for(int i=0;i<e;i++) {
        if(bfs(i)){
            continue;
        } 
        ans = false;
        while(!q.empty()) q.pop();
    }

    cout << (ans ? "YES":"NO") << '\n';
    


}

int main()
{
    int tc;
    cin >> tc;

    for(int i=0;i<tc;i++){
        execute();
    }

    return 0;
}