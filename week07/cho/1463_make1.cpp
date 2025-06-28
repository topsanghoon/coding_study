#include <iostream>
using namespace std;
#include <vector>

vector<int> dp;

int dfs(int num , int count){
    if(num<=1){
        //cout<<" num: "<<num<<" count: "<<count<<'\n';
        return 0;

    } 
    if(dp[num]<count){
        return dp[num];
    }

    int min = 1000000;

    if(num%3==0){
        int m3 = dfs(num/3 , count +1);
        if(m3 < min) min = m3;
    }
    if(num%2==0){
        int m2 = dfs(num/2 , count +1);
        if(m2 < min) min = m2;
    }
    int m1 = dfs(num-1, count + 1);
    if(m1 <min) min=m1;

    dp[num]=min +1;
    return min+1;
}



int main() {
    int N;
    cin>>N;
    dp.assign(N+1, 1000000);
    dp[1]=0;
    dfs(N,0);
    // for (int i=0; i<=N; i++) {
    //     cout<<"dp"<<i<<"번 = "<<dp[i]<<'\n';
    // }
    cout<<dp[N];
    
    return 0;
}