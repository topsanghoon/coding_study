#include <stdio.h>

#define INT_MAX 2147483647
#define MAX_N (13+1)
#define START_COMPANY 1

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

int arr[MAX_N][MAX_N] = {0};
int visited[MAX_N] = {0};

int min_value = INT_MAX;
int n;

void input();
void dfs(int start, int cur_value, int depth);

int main(){
    
    input();

    visited[START_COMPANY] = 1;
    dfs(START_COMPANY,0,1);

    printf("%d\n",min_value);
    return 0;
}

void input(){
    scanf("%d",&n);   

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d ", &arr[i][j]);
        }
    }
}

void dfs(int start, int cur_value, int depth){
    
    if(depth == n){ // 1번제외 모든 회사를 둘러봤을 경우

        if(!arr[start][START_COMPANY]) return; //마지막 회사에서 1번 회사로 돌아갈 수 없으면 함수종료

        cur_value += arr[start][START_COMPANY];
        min_value = MIN(min_value, cur_value);
        return ;
    }

    if(cur_value >= min_value){
        return ;
    }

    for(int i=2;i<=n;i++){
        
        if(visited[i] || !arr[start][i]) continue;

        visited[i] = 1;
        dfs(i,cur_value + arr[start][i], depth+1);
        visited[i] = 0;
    }
}