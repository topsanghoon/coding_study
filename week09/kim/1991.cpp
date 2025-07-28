#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<char>> graph;
stack<char> stk;
vector<char> ans[3];

void dfs(int start){
    
    for(int i=0;i<2;i++){
        if(graph[start][i]!='.'){
            ans[0].push_back(graph[start][i]);
            dfs(graph[start][i]-'A');
            ans[2].push_back(graph[start][i]);            
        }
        if(i==0)ans[1].push_back(start+'A');
    }
}

int main(){

    int n;
    cin >> n;

    for(int i=0;i<3;i++){
        ans[i] = vector<char>(0);
    }
    graph = vector<vector<char>>(n,vector<char>(2,0));
    

    char num,a,b;
    for(int i=0;i<n;i++){
        cin >> num;
        cin >> graph[num-'A'][0];
        cin >> graph[num-'A'][1];
    }
    ans[0].push_back('A');
    dfs(0);
    ans[2].push_back('A');

    for(int i=0;i<3;i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
    return 0;
}