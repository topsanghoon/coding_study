#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<bool> visited;
vector<bool> unvisited;

vector<vector<int>> edice;
priority_queue<int, vector<int>> pq1;
priority_queue<int, vector<int>> pq2;
vector<int> answer;
int n;
int mx = 0;

void diceAdd(int start, int sum, int depth, bool status){
    
    if(depth == n/2){
        if(status) pq1.push(sum);
        else pq2.push(sum);
        return ;
    }
    
    for(int i=start;i<n;i++){
        if(status && visited[i] == true){
            visited[i] = false;
            for(int j=0;j<6;j++){
                diceAdd(i,sum+(edice[i][j]), depth+1, status);
            }
            visited[i] = true;
            
        }
        if(!status && unvisited[i] == true){
            unvisited[i] = false;
            for(int j=0;j<6;j++){
                diceAdd(i,sum+(edice[i][j]), depth+1, status);
            }
            unvisited[i] = true;
        }
    }
}

void dfs(int start, int depth){
    vector<int> tmp;
    if(depth == n/2) {
        for(int i=0;i<n;i++){
            if(visited[i]) tmp.push_back(i+1);
        }
        diceAdd(0,0,0,true); // 선택된 주사위 조합으로 나올 수 있는 합들을 pq1 에 push함
        diceAdd(0,0,0,false);// 선택되지 않은 주사위 조합으로 나올 수 있는 합들을 pq2 에 push함
        
        int sum = 0;
        //cout << pq1.size() << " "  << pq2.size() << '\n';
                
        while(!pq1.empty() && !pq2.empty()){
            if(pq1.top() > pq2.top()){
                pq1.pop();
                sum += pq2.size();
            } else {
                pq2.pop();
            }
        }
        
        if(sum > mx){
            mx = sum;
            answer = tmp;
        }   
        cout << sum << '\n';
        while(!pq1.empty()) pq1.pop();
        while(!pq2.empty()) pq2.pop();
        return ;
    }
    
    for(int i=start;i<n;i++){
        if(visited[i] == false){
            visited[i] = true;
            unvisited[i] = false;
            
            dfs(i,depth+1);
            
            visited[i] = false;
            unvisited[i] = true;
        }
    }
}


vector<int> solution(vector<vector<int>> dice) {
    
    
    edice = dice;
    
    n = dice.size();
    visited = vector<bool>(n, false);
    unvisited = vector<bool>(n, true);
    
    dfs(0,0);

    return answer;
}