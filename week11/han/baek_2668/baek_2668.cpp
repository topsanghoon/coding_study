#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

// 숫자 고르기
// https://www.acmicpc.net/problem/2668
int visited[100+1] = {0, };
int graph[100+1];
int N;
vector<int> answer;
// bool dfs(int count, int destination, int check){
//     if(count > N+1) return false;
//     if(visited[destination] == 1 && graph[destination] == check) return true;

//     visited[destination] = 1;
//     if(dfs(count+1, graph[destination], check)) {
//         answer.push_back(destination);
//         return true;
//     }
//     return false;
// }

bool dfs(int destination, int check){
if (visited[destination]) return false;
visited[destination] = 1;

int next = graph[destination];
if (dfs(next, check)) {
    answer.push_back(destination);
    return true;
}

if (next == check) {
    answer.push_back(destination);
    return true;
}

return false;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cin >> graph[i];
    }

    for(int i = 1; i <= N; i++){
        // visited[i] = 1;
        dfs(i, i);
        memset(visited, 0, sizeof(visited));
    }
    // cout << "\n";
    // cout << answer.size() << "\n";
    // for(int i = 0; i < (int)answer.size(); i++){
    //     cout << answer[i] << " ";
    // }

    set<int> s;
    for(int i = 0; i < (int)answer.size(); i++){
        s.insert(answer[i]);
    }

    cout << s.size() << "\n";

    for(int i : s){
        cout << i << "\n";
    }
}