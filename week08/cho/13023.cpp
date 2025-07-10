#include <iostream>
#include<vector>
using namespace std;
vector<vector<int>> arr;
vector<int> visited;

int ans;
void DFS(int cnt,int num){
    if(visited[num] ==1) return;  // 중복된 숫자에 접근했을때 return 반환
    if(cnt>=4){   // 4 이상 되었을때 친구관계가있다고 판정하고 return 
        ans=1;
        return;
    }
    
    visited[num] = 1; // 해당 숫자 방문 처리 
    

    for (int i=0; i<size(arr[num]);i++ ) {
        DFS(cnt+1 , arr[num][i]);
        if(ans) return;
    }
    visited[num] = 0;
}

int main() {
    int N,M;
    cin>>N>>M;
    arr = vector<vector<int>>(N);
    visited = vector<int>(N,0);
    ans =0;
    for (int i=0; i<M; i++) {
        int x,y;
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    for(int i=0;i<N;i++){
        if(visited[i]==0){
         
            DFS(0,i);
            visited[i]=0;
            if(ans>=4) break;   
        }
    }
    cout<<ans;
    return 0;
}