//https://www.acmicpc.net/problem/2252
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> degree;
vector<vector<int>> map;

int main() {
    int N,M;
    cin>>N>>M;
    degree.resize(N+1,0);
    map.resize(N+1);

    int temp,temp1;
    for(int i=0;i<M;i++){
        cin>>temp>>temp1;
        map[temp].push_back(temp1);
        degree[temp1]++;
    }
    
    queue<int> q;
    //진입차수 0인것 전부 큐에 삽입
    for(int i=1;i<N+1;i++){
        if(degree[i]==0) q.push(i);
    }
    
    //위상 정렬 1~N 쭉 탐색하다가 큐가 비면 사이클이 존재 하는것이다.
    for(int i=1;i<N+1;i++){
        int num=q.front(); q.pop();
        cout<<num<<" ";
        for(int j=0;j<map[num].size();j++){
            int new_num = map[num][j];
            if(--degree[new_num] == 0) q.push(new_num);
        }
    }
    
    
    
    // for(int i=1; i<=N; i++){
    //     for(int j=0; j < map[i].size(); j++){
    //         cout <<i<<" "<<map[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    
    
    return 0;
}