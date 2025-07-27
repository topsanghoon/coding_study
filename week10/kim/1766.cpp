#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> degree;
vector<vector<int>> graph;
priority_queue<int,vector<int>,greater<>> pq;

int main(){

    int n,m;
    cin >> n >> m;
    degree = vector<int>(n+1,0);
    graph = vector<vector<int>>(n+1, vector<int>());

    int f,s;
    for(int i=0;i<m;i++){
        cin >> f >> s;
        graph[f].push_back(s);
        degree[s]++;
    }
    for(int i=1;i<=n;i++){
        if(degree[i]==0){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        int pqtop = pq.top();
        pq.pop();
        cout << pqtop<< " ";
        int next;
        for(int i=0;i<graph[pqtop].size();i++){
            next = graph[pqtop][i];
            degree[next]--;
            if(degree[next]==0){
                pq.push(next);
            }
        }
    }

    return 0;
}