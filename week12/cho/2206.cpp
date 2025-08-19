#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
vector<vector<int>> map;
vector<vector<vector<int>>> visited;
int Row_Map,Col_Map;

struct node{
    int cur_row,cur_col,cur_cnt,cur_total;
};

int drow[4]={0,0,1,-1};
int dcol[4]={1,-1,0,0};
int ans=0;
void BFS(int init_Row,int init_Col,int Cnt,int Total){
    queue<node> q;
    q.push({init_Row,init_Col,Cnt,Total});
    visited[init_Row][init_Col][Cnt]=Total+1;
    //cout<<"BFS 진입!!"<<'\n';

    while(!q.empty()){
        //cout<<"while 진입!!"<<'\n';
        node x=q.front();
        q.pop();
        //cout<<"Row:"<<x.cur_row<<" Col:"<<x.cur_col<<" Cnt:"<<x.cur_cnt<<" Total:"<<x.cur_total<<'\n';
        if(x.cur_row==Row_Map &&x.cur_col==Col_Map){
            ans=x.cur_total;
            break;
        } 

        for(int i=0;i<4;i++){
            int next_row=x.cur_row+drow[i];
            int next_col=x.cur_col+dcol[i];
            if(next_row<1 || next_row >Row_Map || next_col<1 || next_col >Col_Map) continue;
            if(visited[next_row][next_col][x.cur_cnt] >0) continue;
            if(map[next_row][next_col]==1){
                if(x.cur_cnt==0){
                    q.push({next_row,next_col,x.cur_cnt+1,x.cur_total+1});
                    visited[next_row][next_col][x.cur_cnt+1]=x.cur_total+1;                    
                }
            }
            else{
                q.push({next_row,next_col,x.cur_cnt,x.cur_total+1});
                visited[next_row][next_col][x.cur_cnt]=x.cur_total+1;
            }
        }
    }
    
}

int main() {
    cin>>Row_Map>>Col_Map;
    map.resize(Row_Map+1,vector<int>(Col_Map+1,0));
    visited.resize(Row_Map + 1, vector<vector<int>>(Col_Map + 1, vector<int>(2, -1))); //row,col,벽부수고 안부수고
    
    for(int i=1;i<=Row_Map;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<Col_Map;j++){
            map[i][j+1] = temp[j] - '0';
        }
    }
    BFS(1,1,0,1); // (1,1)좌표에서 시작 , cnt=0 , total=0;
    // for(int i=1;i<=Row_Map;i++){
    //     for(int j=1;j<=Col_Map;j++){
    //         cout<<map[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }

    if(ans==0){
        cout<<-1;
        return 0;
    } 
    cout<<ans;
    return 0;
}