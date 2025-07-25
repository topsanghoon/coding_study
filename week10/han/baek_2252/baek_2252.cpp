#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 줄 세우기
// https://www.acmicpc.net/problem/2252
vector<int> indegree(32001,0);
vector<vector<int>> graph(100000+1,vector<int>(0));

int N, M;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        int first, second;
        cin >> first >> second;
        graph[first].push_back(second);
        indegree[second] += 1;
    }

    vector<int> answer;
    queue<int> q;

    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        answer.push_back(now);

        for(int i = 0; i < (int)graph[now].size(); i++){
            int next = graph[now][i];
            indegree[next] -= 1;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }

    for(int i = 0; i < (int)answer.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}