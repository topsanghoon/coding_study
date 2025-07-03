#include <iostream>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/13023
// ABCDE
vector<vector<int>> graph(2000);
int visited[2000] = {0,};
int peopleCnt, relationCnt;
int answer = 0;

void dfs(int N, int start){
    if(answer == 1) return;
    if(N == 5) {
        answer = 1;
        return;
    } 
    for(int i = 0; i < (int)graph[start].size(); i++){
        // cout << "here: " << i << " " << graph[start][i] << " " << (int)graph[start].size() <<"\n";
        if(visited[graph[start][i]] == 0){
            visited[graph[start][i]] = 1;
            dfs(N+1, graph[start][i]);
            visited[graph[start][i]] = 0;
        }
        else continue;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> peopleCnt >> relationCnt;
    
    int left, right;
    for(int i = 0; i < relationCnt; i++){
        cin >> left >> right;
        graph[left].push_back(right);
        graph[right].push_back(left);
    }

    for(int i = 0; i < peopleCnt; i++){
        visited[i] = 1;
        dfs(1,i);
        visited[i] = 0;
    }
    cout << answer << "\n";

    // for(int i = 0; i < peopleCnt; i++){
    //     for(int j = 0; j < (int)graph[i].size(); j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

}