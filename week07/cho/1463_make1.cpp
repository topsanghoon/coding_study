#include <iostream>
using namespace std;
#include <vector>

vector<int> dp;

/*
10->5->4->2->1 갔다고 가정 했을때
재귀를 사용해서 1인 마지막지점에 도달했을때 0을 리턴
1에서 10으로 올라가면서 1을 더하면서 DP 백터에 저장 -> 
이후에 같은 num이 왔을때 최소값으로 리턴 할수 있다. 

count를 써서 1로 도달하는 중에 관찰할수 있는 변수를 지정해 dp벡터 최소예정값과 비교함으로써
가지치기를 할수 있다. ->메모리 아끼기 
*/

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