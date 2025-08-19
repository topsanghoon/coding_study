#include <iostream>

using namespace std;

int dp[2][31][1000];
int arr[1000] = {};

int main()
{

    int t,w;
    cin >> t >> w;
    for(int i=0;i<t;i++){
        cin >> arr[i];
        arr[i]--;
    }
    
    dp[0][0][0] = !arr[0];
    dp[1][1][0] = arr[0]; // 처음 위치가 정해져있음
    

    for(int i=1;i<t;i++){

        dp[0][0][i] = dp[0][0][i-1];
        dp[1][0][i] = dp[1][0][i-1];

        for(int j=1;j<=w;j++){
            
            if(arr[i]){
                dp[1][j][i] = 
                    max(dp[1][j][i-1], dp[0][j-1][i-1]);
                dp[0][j][i] = dp[0][j][i-1];
            }
            else {
                dp[0][j][i] = 
                    max(dp[0][j][i-1], dp[1][j-1][i-1]);
                dp[1][j][i] = dp[1][j][i-1];
            }
        }
        for(int j=0;j<=w;j++){
            dp[arr[i]][j][i]++;
        }
    }

    // for(int j=0;j<=w;j++){
    //     for(int i=0;i<t;i++){
    //         cout << dp[0][j][i] << " ";
    //     }
    //     cout << endl;
    //     for(int i=0;i<t;i++){
    //         cout << dp[1][j][i] << " ";
    //     }
    //     cout << endl;
    // }

    int mx = 0;
    for(int i=0;i<=w;i++){
        mx = max(mx, dp[0][i][t-1]);
        mx = max(mx, dp[1][i][t-1]);
    }
    cout << mx;
    return 0;
}