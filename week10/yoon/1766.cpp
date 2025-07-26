#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;

    vector<int> pointing_num_of_problem(N+1, 0);
    vector<vector<int>> pointing_list(N+1);

    for(int i = 0; i < M; i++){
        int from, to;
        cin >> from >> to;
        pointing_list[from].push_back(to);
        pointing_num_of_problem[to]++;
    }

    priority_queue <int, vector<int>, greater<int>> q;
    for(int i = 1; i <= N; i++){
        if(pointing_num_of_problem[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int now = q.top();
        q.pop();
        cout << now << " ";

        for(int who : pointing_list[now]){
            pointing_num_of_problem[who] -= 1;
            if(pointing_num_of_problem[who] == 0) q.push(who);
        }
    }

    return 0;
}