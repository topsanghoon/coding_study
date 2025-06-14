#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n,m;
    cin >> n >> m;
    bool nums[10000001];
    memset(nums,true,10000001*sizeof(bool));

    
    for(long long i=2;i*i<=m;i++){
        if(!nums[i]) continue;

        long long next = i*2;
        while(next*next <= m){
            nums[next] = false;
            next += i;
        }
    }
    
    int ans = 0;
    for(long long i=2;i*i<=m;i++){
        if(nums[i]){
            long long a = i*i;
            while(a<=m){
                if(n<=a){
                   ans++; 
                }
                if (a > m /i) break; // N제곱을 하면 long long 범위를 초과하는 경우 발생
                a *= i;
            }
        }
    }

    cout << ans << '\n';
    
}

