#include <stdio.h>
#define MAX_N (20+1)
#define INT_MAX 2147483647

#define MIN(X,Y) ((X<Y)?(X):(Y))
#define ABS(X) ((X<0)?-(X):(X))

int dp[MAX_N][MAX_N][MAX_N] = {};
int quest[MAX_N] = {};
int min_cnt = INT_MAX;
int m;


int main() {    
    int n;
    scanf("%d",&n);

    for(int i=0;i<MAX_N;i++){
        for(int j=0;j<MAX_N;j++){
            for(int k=0;k<MAX_N;k++){
                dp[i][j][k] = INT_MAX;
            }
        }
    }
    
    int a,b;
    scanf("%d %d",&a, &b);
    dp[0][a][b] = 0;
    

    
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&quest[i]);
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dp[i-1][j][k]==INT_MAX) continue;

                dp[i][quest[i]][k] = MIN(dp[i][quest[i]][k],dp[i-1][j][k] + ABS(j-quest[i]));
                dp[i][j][quest[i]] = MIN(dp[i][j][quest[i]],dp[i-1][j][k] + ABS(k-quest[i]));
                
            }
        }
    }
    
    int min_cnt = INT_MAX;
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
            min_cnt = MIN(min_cnt,dp[m][j][k]);
        }
    }
    
    printf("%d\n",min_cnt);
    return 0;
}