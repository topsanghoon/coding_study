#include <iostream>
#include <vector>
using namespace std;

// 트리의 지름
// https://www.acmicpc.net/problem/1167
vector<vector<int>> graph(100000+1);
int gMax = 0;
int lastNode = 0;
void dfs(vector<int> &visited, int start, int tMax){
    if(gMax < tMax) {
        gMax = tMax;
        lastNode = start;
    }
    for(int i = 0; i < (int)graph[start].size(); i += 2){
        int startNode = graph[start][i];
        int costStartNode = graph[start][i+1];
        // cout << startNode << " " << costStartNode << " " << tMax << " " << visited[startNode] << "\n";
        if(visited[startNode] == 0) {
            visited[startNode] = 1;
            dfs(visited, startNode, tMax+costStartNode);
            // visited[startNode] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> visited1(N+1);
    vector<int> visited2(N+1);
    for(int i = 1; i <= N; i++){
        int row;
        cin >> row;
        int temp = 0;
        while(temp!=-1){
            cin >> temp;
            if(temp != -1) graph[row].push_back(temp);
        }
    }

    
    // cout << "\n";

    // for(int i = 1; i <= N; i++){
    //     for(int j = 0; j < (int)graph[i].size(); j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

        // cout << "\n";

    // for(int i = 1; i <= N; i++){
    //     visited[i] = 1;
    //     dfs(visited, i, 0);
    //     // visited[i] = 0;
    // }

    visited1[1] = 1;
    dfs(visited1, 1, 0);

    // cout << lastNode << "\n";

    // cout << "\n";

    visited2[lastNode] = 1;
    dfs(visited2, lastNode, 0);

    cout << gMax;


}