#include <stdio.h>
#define ARR_MAX 100010
#define MAX(A,B) ((A<B) ? (B) : (A))
int main() {
    int n;
    scanf("%d ",&n);
    int arr[ARR_MAX] = {};
    int sum_arr[ARR_MAX] = {};
    int dp[ARR_MAX] = {};
    
    for(int i=1;i<=n;i++){
        scanf("%d ",&arr[i]);
    }

    sum_arr[1] = arr[1];
    dp[1] =  arr[1];

    int ans = dp[1];

    if(n==1){
        printf("%d\n",ans);
        return 0;
    }
    
    for(int i=2;i<=n;i++){
        sum_arr[i] = MAX(sum_arr[i-1]+arr[i],arr[i]);
        dp[i] = MAX(dp[i-1]+arr[i],MAX(sum_arr[i], sum_arr[i-1]));
        //printf("%d %d %d\n",dp[i-1]+arr[i],sum_arr[i],sum_arr[i-1]);
        ans = MAX(ans,dp[i]);
    }

    printf("%d\n",ans);
    
    return 0;
}