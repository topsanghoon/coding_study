#include <stdio.h>
#define MAX 2001

char arr[MAX][MAX] = {};
char visited[MAX] = {};
int ans = 0;
void dfs(int start,  int depth, int n){
    if(depth>=5){
        ans = 1;
    }
    if(ans==1){
        return ;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==0 && arr[start][i]==1){

            visited[i]=1;
            dfs(i,depth+1,n);
            visited[i]=0;
        }
    }
}

int main(){

    int n,m;
    scanf("%d %d ",&n,&m);

    int from, to;
    for(int i=0;i<m;i++){
        scanf("%d %d ",&from,&to);
        arr[from][to] = 1;
        arr[to][from] = 1;
    }

    for(int i=0;i<n;i++){
        visited[i] = 1;
        dfs(i,1,n);
        visited[i] = 0;
    }
    printf("%d\n",ans);
    return 0;
}