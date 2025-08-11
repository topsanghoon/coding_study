//https://www.acmicpc.net/problem/2668
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<int> map1;
vector<int> visited;
vector<int> temp;
bool check=false;

void DFS(int cur,int num){
    temp.push_back(cur);
    //cout<<cur<<" ";
    int next = map1[cur];
    //cout<<next<<'\n';
    if(next == num){
        check=true;        
        return;    
    } 

    if(visited[next]==1) return;
    visited[next]=1;
    DFS(next,num);
    visited[cur]=0;
}

int main() {
    int N;
    cin>>N;
    map1.resize(N+1,0);
    visited.resize(N+1,0);
    
    for(int i=1;i<=N;i++){
        cin>>map1[i];
    }
    set<int> res;
    for(int i=1;i<=N;i++){
        DFS(i,i);
        if(check){
            res.insert(temp.begin(),temp.end());
        }
        //cout<<"res size: "<<res.size()<<" temp size: "<<temp.size()<<'\n';
        temp.clear();
        check=false;
        
        
    }
    //sort(res.begin(), res.end());
    cout<<res.size()<<'\n';
    for(int ch:res) cout<<ch<<'\n';
    
    // if(check){
    //     cout<<'\n'<<temp.size();
    // }
    // else{
    //     cout<<'\n'<<0;
    // }
    //
    
}
