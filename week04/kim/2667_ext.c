#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** graph;
int* ans = NULL;
int n;

int dfs(int y, int x);
void memRelease();
int compare(const void* a, const void* b);

int main() {

    scanf("%d ",&n);
    
    graph = (int**)malloc((n+2)*sizeof(int*));
    if(graph == NULL){
        free(graph);
        exit(1);
    }

    for(int i=0;i<n+2;i++){
        graph[i] = (int*)malloc((n+2)*sizeof(int));
        
        if(*graph == NULL){
            for(int j=0;j<i;j++){
                free(graph[j]);
                exit(1);
            }
        }
        memset(graph[i],0,((n+2)*sizeof(int)));
    }

    for(int i=1;i<=n;i++){
        char line[26];
        scanf("%s",line);
        for(int j=1;j<=n;j++){
            graph[i][j] = line[j-1] - '0';
        }
    }

    int size = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(graph[i][j] == 1){
                ans = realloc(ans,(++size)*sizeof(int));
                if(ans == NULL){
                    memRelease();
                }
                ans[size-1] = dfs(i,j);
            }
        }
    }
    
    qsort(ans,size,sizeof(ans[0]),compare);
    
    printf("%d\n",size);
    for(int i=0;i<size;i++){
        printf("%d\n",ans[i]);
    }
    
    memRelease();
    free(ans);
    ans = NULL;
    
    return 0;
}

int dfs(int y, int x){

    int ans = 0;
    
    graph[y][x] = 0;
    ans++;
    
    int ny[4] = {1,-1,0,0};
    int nx[4] = {0,0,1,-1};

    int nexty;
    int nextx;
    for(int i=0;i<4;i++){

        nexty = ny[i]+y;
        nextx = nx[i]+x;

        if(graph[nexty][nextx]==1){
            ans += dfs(nexty,nextx);
        }
    }
    return ans;
}

void memRelease(){

    if(ans != NULL) {
        free(ans);
        ans = NULL;
    }

    if(graph == NULL) continue;
    
    for (int i = 0; i < n+2; i++) {
        free(graph[i]);
    }
    free(graph);
    graph = NULL;
}

int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return (x<y) - (y-x);
}