#include <iostream>
using namespace std;

int dp[101][1024][10] {};

int main(){

    int n;
    cin >> n;

    for(int i=1;i<=9;i++){
       // cout<<(1<<i) << " ";
        dp[1][1<<i][i] = 1;
    }

    for(int i=1;i<=n-1;i++){
        for(int j=1;j<1024;j++){
            int pre, nxt, nextIdx;
            for(int k=0;k<=9;k++){
                if(dp[i][j][k] == 0) continue;
                pre = k-1;
                nxt = k+1;

                nextIdx = j;
                if(pre>=0){
                    nextIdx |= (1<<pre);
                    //cout<<i+1<<" "<<nextIdx<<"\n";
                    dp[i+1][nextIdx][pre] += (dp[i][j][k])%1000000000;
                }
                nextIdx = j;
                if(nxt<=9){
                    nextIdx |= (1<<nxt);
                    dp[i+1][nextIdx][nxt] += (dp[i][j][k])%1000000000;
                }

            }


        }
    }
    long long ans = 0;
    for(int i=0;i<=9;i++){
        ans = (ans + dp[n][1023][i])%1000000000;
    }

    cout<<ans;
    

    return 0;
}