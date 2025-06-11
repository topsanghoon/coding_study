#include <iostream>
#include <stack>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a;
    stack<int> stk;

    long long ans = 0;
    
    for(int i=0;i<n;i++){
        cin >> a;
        while(!stk.empty() && stk.top() <= a){
            stk.pop();
        }
        stk.push(a);
        ans += (long long)stk.size()-1;
    }

    cout<<ans<<'\n';
    
    return 0;
}