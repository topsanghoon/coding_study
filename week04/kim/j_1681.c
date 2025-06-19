#include <stdio.h>


#define INT_MAX 2147483647
#define MAX_N 13
#define START_COMPANY 1

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

int arr[MAX_N + 1][MAX_N + 1] = {0};
int visited[MAX_N + 1] = {0};
int min_value = INT_MAX;
int n;

void dfs(int start, int cur_value, int depth);

int main(){

    
    scanf("%d",&n);   

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d ", &arr[i][j]);
        }
    }
    visited[START_COMPANY] = 1;
    dfs(START_COMPANY,0,1);
    printf("%d\n",min_value);
    return 0;
}

void dfs(int start, int cur_value, int depth){
    
    if(depth == n){
        if(!arr[start][START_COMPANY]) return;
        cur_value += arr[start][START_COMPANY];
        min_value = MIN(min_value, cur_value);
        return ;
    }

    if(cur_value >= min_value){
        return ;
    }

    for(int i=1;i<=n;i++){
        
        if(visited[i] || !arr[start][i]) continue;
        visited[i] = 1;
        dfs(i,cur_value + arr[start][i], depth+1);
        visited[i] = 0;
    }
}