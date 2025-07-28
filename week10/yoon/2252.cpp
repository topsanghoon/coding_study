#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> relationship(n + 1);
    vector<int> pointing_num (n+1, 0);

    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        relationship[from].push_back(to);
        pointing_num[to]++;
    }

    queue <int> q;

    for(int i = 1; i <= n; i++){
        if(pointing_num[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int current = q.front();
        q.pop();
        pointing_num[current] -= 1;
        cout << current << " ";

        for(int next : relationship[current]){
            pointing_num[next] -= 1;

            if(pointing_num[next] == 0) q.push(next);
        }
    }

    for(int i = 1; i <= n; i++){
        if(pointing_num[i] >= 0) cout << i << " ";
    }

    return 0;
}