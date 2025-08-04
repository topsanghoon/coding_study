#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<bool> is_cycle;
vector<int> graph;

int n;
bool dfs(int start, int origin_start){

    visited[start] = true;
    //cout << "start: "<<start<<" origin_start: "<<origin_start<<'\n';
    
    if(graph[start] == origin_start){
        is_cycle[start]=true;
        return true;
    }

    if(visited[graph[start]]){
        return false;
    }

    
    bool ret = dfs(graph[start],origin_start);    
    return ret;
}

void debug(){
    for(int i=1;i<=n;i++){
            
        if(is_cycle[i]){
             cout << i <<" ";
        }
    }
     cout << '\n';
}

int main(){


    cin >> n;
    
    is_cycle = vector<bool>(n+1);
    graph = vector<int>(n+1);

    int s;
    for(int i=1;i<=n;i++){
        cin >> graph[i];
    }
    
    for(int i=1;i<=n;i++){
        visited = vector<bool>(n+1,false);
        visited[i] = true;
        is_cycle[i] = dfs(graph[i],i);
    }
    
    int answer_num=0;
    for(int i=1;i<=n;i++){
        if(is_cycle[i]) answer_num++;
    }
    cout<<answer_num<<'\n';
    for(int i=1;i<=n;i++){
        if(is_cycle[i]) cout<<i<<'\n';
    }

    return 0;
}