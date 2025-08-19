//https://jungol.co.kr/problem/1889?cursor=OCw1LDE%3D
#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> visited;
int res=0;
int N;
vector<int> col;


bool Queen_check(int row){
    for(int i=0;i<row;i++){
        if(col[i] == col[row] || abs(col[row] - col[i]) == row -i){
            return false;
        }
    }
    return true;
}

void DFS(int cur_col) {
    if(cur_col == N) {  
        res++;
    }
    else{
        for(int i=0;i<N;i++){
            col[cur_col] = i;
            if(Queen_check(cur_col)){
                DFS(cur_col+1);
            }
        }
    }

}

int main() {

    cin>>N;
    col.resize(N);
    DFS(0);
    cout<<res;
    return 0;
}


//참고 링크: https://cryptosalamander.tistory.com/58
