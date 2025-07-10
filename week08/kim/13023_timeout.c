#include <stdio.h>
#define MAX 2001

int arr[MAX][MAX] = {};
int idxes[MAX] = {};
char visited[MAX] = {};
int ans = 0;

void dfs(int start,  int depth, int n){
    if(depth>=5){
        ans = 1;
    }
    if(ans==1){
        return ;
    }
    for(int i=0;i<idxes[start];i++){

        int next = arr[start][i];

        if(visited[next]==0){

            visited[next]=1;
            dfs(next,depth+1,n);
            visited[next]=0;
        }
    }
}

int main(){

    int n,m;
    scanf("%d %d ",&n,&m);

    int from, to;
    for(int i=0;i<m;i++){
        scanf("%d %d ",&from,&to);
        arr[from][idxes[from]++] = to;
        arr[to][idxes[to]++] = from;
    }

    for(int i=0;i<n;i++){
        visited[i] = 1;
        dfs(i,1,n);
        visited[i] = 0;
    }
    printf("%d\n",ans);
    return 0;
}