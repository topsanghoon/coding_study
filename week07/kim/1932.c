#include <stdio.h>
#define MAX_ARR (500+2)
#define MAX(A,B) ((A < B) ? (B) : (A))
int main(){

    int n;
    scanf("%d " ,&n);
    int dp[MAX_ARR][MAX_ARR];

    int tmp_input;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d " ,&tmp_input);
            dp[i][j] += tmp_input;
            dp[i+1][j] = MAX(dp[i+1][j],dp[i][j]);
            dp[i+1][j+1] = MAX(dp[i+1][j+1],dp[i][j]);
        }
    }
    
    int answer = 0;
    for(int i=1;i<=n;i++){
       answer = MAX(answer, dp[n][i]);
    }
    
    printf("%d\n",answer);
    return 0;
}