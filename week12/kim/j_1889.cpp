#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> visited;
vector<bool> colVisited;

int n;
int ans = 0;

// 대각선 부분만 확인
void put_queen(int y, int x){ // 시간복잡도 O((N/2) * 4) = O(N*2)

    int tmpy = y;
    int tmpx = x;
    while(tmpy>=1 && tmpx>=1){
        visited[--tmpy][--tmpx]++;
    }
    tmpy = y;
    tmpx = x;
    while(tmpy<n-1 && tmpx<n-1){
        visited[++tmpy][++tmpx]++;
    }
    tmpy = y;
    tmpx = x;
    while(tmpy<n-1 && tmpx>=1){
        visited[++tmpy][--tmpx]++;
    }
    tmpy = y;
    tmpx = x;
    while(tmpy>=1 && tmpx<n-1){
        visited[--tmpy][++tmpx]++;
    }
}

void remove_queen(int y, int x){ // 시간복잡도 O((N/2) * 4) = O(N*2)

    int tmpy = y;
    int tmpx = x;
    while(tmpy>=1 && tmpx>=1){
        visited[--tmpy][--tmpx]--;
    }
    tmpy = y;
    tmpx = x;
    while(tmpy<n-1 && tmpx<n-1){
        visited[++tmpy][++tmpx]--;
    }
    tmpy = y;
    tmpx = x;
    while(tmpy<n-1 && tmpx>=1){
        visited[++tmpy][--tmpx]--;
    }
    tmpy = y;
    tmpx = x;
    while(tmpy>=1 && tmpx<n-1){
        visited[--tmpy][++tmpx]--;
    }
}

void dfs(int y, int x){ 

    //cout << depth<< " ";
    if(y == n-1){
        ans ++;
        return ;
    }

    for(int i=0;i<n;i++){
        if(visited[y+1][i]>0) continue;
        if(colVisited[i]) continue;
        put_queen(y+1,i);
        colVisited[i] = true;
        dfs(y+1,i);
        colVisited[i] = false;
        remove_queen(y+1,i);
    }

}

int main(){
    
    cin >> n;
    visited = vector<vector<int>>(n,vector<int>(n,0));

    colVisited = vector<bool>(n,0); // 전제조건: 

    for(int i=0;i<n;i++){
        put_queen(0,i);
        colVisited[i] = true;
        dfs(0,i);
        colVisited[i] = false;
        remove_queen(0,i);
    }

    cout << ans << '\n';
}
