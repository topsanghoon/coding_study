#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> star_map;

void insert_map(int row,int col){
    for(int i =row;i<row+3;i++){
        for(int j=col;j<col+3;j++){
            if(i==row+1 && j==col+1) continue;
            star_map[i][j] = '*';
            }
        }
}

void star(int N, int row, int col){
    if(N==3){
        insert_map(row,col);
    }else{
        int unit=N/3;
        for(int i = 0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==1 && j==1) continue;
                star(unit,row+i*unit,col+j*unit);
            }
        }
    }
}

int main() {
    int N;
    cin>>N;
    star_map.assign(N,vector<char>(N,' '));
    star(N,0,0);

    for (int i=0; i<N; i++) {
        for(int j=0;j<N;j++){
            cout<<star_map[i][j];
        }
        cout<<'\n';        
    }
    
    return 0;
}