#include <stdio.h>
#include <stdlib.h>
#define MAX(A,B) ((A<B) ? (B) : (A))

int main(){

    int n;
    scanf("%d ",&n);

    int* arr = calloc(n+1,sizeof(int));
    int* dp = calloc(n+1,sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d ",&arr[i]);
    }

    if(n==1) {
        printf("%d ",arr[1]);
        return 0;
    }
    if(n==2) {
        printf("%d ",arr[1]+arr[2]);
        return 0;
    }
    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = MAX(arr[1]+arr[2],arr[2]);
    for(int i=3;i<=n;i++){
        int a = dp[i-3]+arr[i-1]+arr[i];
        int b = dp[i-2]+arr[i];
        dp[i] = MAX(a,b);
    }
    printf("%d ",dp[n]);

    return 0;
}