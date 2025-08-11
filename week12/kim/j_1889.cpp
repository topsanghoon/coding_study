#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> visited;
vector<bool> colVisited;
vector<bool> crossVisited1;
vector<bool> crossVisited2;
int n;
int ans = 0;

// // 대각선 부분만 확인
// void put_queen(int y, int x){ // 시간복잡도 O((N/2) * 4) = O(N*2)

//     int tmpy = y;
//     int tmpx = x;
//     while(tmpy>=1 && tmpx>=1){
//         visited[--tmpy][--tmpx]++;
//     }
//     tmpy = y;
//     tmpx = x;
//     while(tmpy<n-1 && tmpx<n-1){
//         visited[++tmpy][++tmpx]++;
//     }
//     tmpy = y;
//     tmpx = x;
//     while(tmpy<n-1 && tmpx>=1){
//         visited[++tmpy][--tmpx]++;
//     }
//     tmpy = y;
//     tmpx = x;
//     while(tmpy>=1 && tmpx<n-1){
//         visited[--tmpy][++tmpx]++;
//     }
// }

// void remove_queen(int y, int x){ // 시간복잡도 O((N/2) * 4) = O(N*2)

//     int tmpy = y;
//     int tmpx = x;
//     while(tmpy>=1 && tmpx>=1){
//         visited[--tmpy][--tmpx]--;
//     }
//     tmpy = y;
//     tmpx = x;
//     while(tmpy<n-1 && tmpx<n-1){
//         visited[++tmpy][++tmpx]--;
//     }
//     tmpy = y;
//     tmpx = x;
//     while(tmpy<n-1 && tmpx>=1){
//         visited[++tmpy][--tmpx]--;
//     }
//     tmpy = y;
//     tmpx = x;
//     while(tmpy>=1 && tmpx<n-1){
//         visited[--tmpy][++tmpx]--;
//     }
// }

void dfs(int y, int x){ 

    //cout << depth<< " ";
    if(y == n-1){
        ans ++;
        return ;
    }

    for(int i=0;i<n;i++){
        if(visited[y+1][i]>0) continue;
        if(colVisited[i]) continue;
        if(crossVisited1[y+1+i]) continue;
        if(crossVisited2[y+1-i+n]) continue;
        //put_queen(y+1,i);
        colVisited[i] = true;
        crossVisited1[y+1+i] = true;
        crossVisited2[y+1-i+n] = true;
        dfs(y+1,i);
        crossVisited1[y+1+i] = false;
        crossVisited2[y+1-i+n] = false;
        colVisited[i] = false;
        //remove_queen(y+1,i);
    }

}

int main(){
    
    cin >> n;
    visited = vector<vector<int>>(n,vector<int>(n,0));

    colVisited = vector<bool>(n,0); // 전제조건: 
    crossVisited1 = vector<bool>(n*2,0);
    crossVisited2 = vector<bool>(n*2,0);

    for(int i=0;i<n;i++){
        //put_queen(0,i);
        colVisited[i] = true;
        crossVisited1[0+i] = true;
        crossVisited2[0-i+n] = true;
        dfs(0,i);
        colVisited[i] = false;
        crossVisited1[0+i] = false;
        crossVisited2[0-i+n] = false;
        //remove_queen(0,i);
    }

    cout << ans << '\n';
}
