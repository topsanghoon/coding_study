#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
vector<vector<int>> v;  // 전역 변수에서 벡터 2차원 행렬 선언 

int dfs(int x,int y){
                //상하좌우  인덱스로 참조 할수 있게 선언
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
                
        int ans = 1;
        // if(v[x][y]==0){  // 밑에 1로처리를 하니까 굳이 필요가 없음. 
        //     return;
        // }
        v[x][y]=0;  //이미 방문 한 곳을 0으로 처리를 하면서 한번더 방문 못하게 셋팅
        
        for (int i=0; i<4; i++) {  // 상하좌우 모두 재귀해서 접근
            
                if(v[x+dx[i]][y+dy[i]]==1){ 
                    ans += dfs(x+dx[i],y+dy[i]);
                }
            /*
            상하좌우중 1인곳에 재귀함수호출한 반환값을  ans에 누적해서 합하기
            */
                    
        }
        return ans;      
}

int main() {
    int N;
    cin>>N;

    v = vector<vector<int>>(N+2,vector<int>(N+2,0));
    
    //2차원 배열 입력 부분 
    for(int i=1; i<=N; i++) {
        string s;
        cin >> s;
        for(int j = 1; j<=N; j++){
            v[i][j] = s[j-1]-'0';
        }
    }
    vector<int> arr;
    
   for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(v[i][j]==1){ // 방문 하지 않은곳만 재귀 함수 호출
                arr.push_back(dfs(i,j));
            }
        }
    }
    // for(int i=0; i<=N+1; i++) {
    //     for(int j=0; j<=N+1; j++) {
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    cout<< arr.size()<<'\n';  // 벡터의 사이즈 출력 해서 몇개 찾았는지 알려주기
    sort(arr.begin(), arr.end());  // 오름차순 정렬해서 출력하기 
    for(int i:arr){  
        cout<<i<<'\n';
    }
    return 0;
}