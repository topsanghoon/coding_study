#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 문제집
// https://www.acmicpc.net/problem/1766
vector<int> inDegree(32000+1,0);
vector<vector<int>> graph(32000+1, vector<int>(0));

int N, M;

vector<int> answer;

int main(void){
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        int first, second;
        cin >> first >> second;
        inDegree[second] += 1;
        graph[first].push_back(second);
    }

    priority_queue<int, vector<int>, greater<int>> q;

    for(int i = 1; i <= N; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int front = q.top();
        q.pop();
        answer.push_back(front);

        for(int i = 0; i < (int)graph[front].size(); i++){
            int next = graph[front][i];
            inDegree[next] -= 1;
            if(inDegree[next] == 0){
                q.push(next);
            }
        }
    }

    for(int i = 0; i < (int)answer.size(); i++){
        cout << answer[i] << " ";
    }

}