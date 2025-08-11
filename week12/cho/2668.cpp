//https://www.acmicpc.net/problem/2668
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> visited;
vector<int> ans;

void DFS(int cur,int num){
    if(visited[cur]==1)//방문 했던 곳에 접근을 했을때 순서도가 끈힌다. 
    {
        if(cur == num) // 마지막 노드랑 첫 노드만 비교 하면 사이클 존재 유무가 가능하다
        {
            ans.push_back(num); // 한 점만 넣는다. 
        }
        return;    
    } 
    visited[cur]=1;
    DFS(arr[cur],num);
    visited[cur]=0;// 일 다 끝나고 나서 최종적으로 백트래킹 할때 복원 시키는 기능 
}

int main(){
    int N;
    cin>>N;
    arr.resize(N+1,0);
    visited.resize(N+1,0);
    
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=N;i++){
        DFS(i,i);
    }
    cout<<ans.size()<<'\n';
    for(auto ch:ans){
        cout<<ch<<'\n';
    }

    
    
    return 0;
}
