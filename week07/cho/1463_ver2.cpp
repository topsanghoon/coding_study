#include <iostream>
using namespace std;
#include <queue>
#include <vector>

/*
BFS로 접근
큐(value,count) 최초값 (1,0) push   x3 ,x2, -1 해서 방문하지않은 곳만 접근해서 
최소값을 무조건 가져올수 있게 규칙을 정의 
메모리: 7540KB   시간: 24ms  

10이 나왔을때 연산을 멈춰 버리면 메모리를 더 아끼는 코드를 생성할수 있음. 

*/

int main() {
    int N;
    cin>>N;
    queue<pair<int,int>> dp;
    vector<int> res(N+1,0);
    dp.push({1,0});
    while(!dp.empty()){
        pair<int,int> num = dp.front();
        int value=num.first;
        int count = num.second;
        //cout<<"num: "<<value <<'\n';
        dp.pop();

        int val3 = value *3;
        int val2= value *2;
        int val1=value +1;
        
        
        if(val3<=N && res[val3]==0) {
            dp.push({val3,count+1});
            res[val3] = count+1;
        }
        if(val2<=N && res[val2]==0 ) {
            dp.push({val2,count+1});
            res[val2] = count+1;
        }
        if(val1<=N && res[val1]==0) {
            dp.push({val1,count+1});
            res[val1] = count+1;
        }
    }
    
    // for (int i=0;i<N+1;i++) {
    //     cout<<i<<"번째: "<<res[i]<<'\n';
    // }

    cout<<res[N];
    return 0;
}