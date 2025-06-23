#include <iostream>
#include <stack>
using namespace std;
int main() {
    int N;
    long long K;
    cin>> N>>K;
    int tmp=0;
    stack<int> coin;
    for(int i=0;i<N;i++){
        cin>>tmp;
        coin.push(tmp);
        
    }

    int res=0;
    int a=0;
    while(!coin.empty() || K!=0){
        a=coin.top();
        coin.pop();
        res += K / a;
        K=K % a;
    }
    cout<<res;
    return 0;
}