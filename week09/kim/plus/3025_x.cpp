#include <iostream>
#include <vector>
#include <deque>
#include <stack>

using namespace std;
vector<vector<char>> arr;
vector<pair<int,int>> dp;
int n,m;
void roll(int y, int x, int first_x);

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    arr = vector<vector<char>> (n+1,vector<char>(m));
    dp = vector<pair<int,int>>(m, make_pair(-1,-1));

    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<m;i++){
        arr[n][i] = 'X';
    }
    
    // for(int i=0;i<m;i++){
    //     while(!stoneAndWall[i].empty()){
    //         cout<<stoneAndWall[i].top()<<" ";
    //         stoneAndWall[i].pop();
    //     }
    //     cout << '\n';
    // }

    int cnt, loc;
    cin >> cnt;
    for(int i = 0; i < cnt; i++){
        cin >> loc;
        roll(0,loc-1, loc-1);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }

    return 0;
}

void roll(int y, int x, int first_x){

    int tmp = y;

    if(y==0 && dp[first_x].first!=-1){
        roll(dp[first_x].first, dp[first_x].second, first_x);
        return ;
    }

    if(arr[y+1][x] == 'X'){
        dp[first_x] = make_pair(-1,-1);
    }
    
    while(arr[y+1][x]=='.') y++;

    if(arr[y+1][x] == 'X'){
        arr[y][x] = 'O';
    }

    if(arr[y+1][x] == 'O'){
         if(0<x 
            && arr[y][x-1]=='.'
            && arr[y+1][x-1]=='.'){
            dp[first_x] = make_pair(y+1,x-1);
            roll(y,x-1, first_x);       
         }
         else if(x<m-1 
            && arr[y][x+1]=='.'
            && arr[y+1][x+1]=='.'){
            dp[first_x] = make_pair(y+1,x+1);
            roll(y,x+1, first_x);
         } 
         else {
            arr[y][x] = 'O';
         }   
    }
}