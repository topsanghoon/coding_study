#include <iostream>
#include <vector>
using namespace std;

bool ispail(int n);

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    while(1){
        if(!ispail(n)){
            n++;
            continue;
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(n%i==0) cnt++;
        }
        if(cnt==2){
            break;
        }
        n++;
    }
    
    cout << n << '\n';
    
    return 0;
}

bool ispail(int n){

    int temp = n;
    int rev = 0;
    
    while(temp){
        rev*=10;
        rev+=temp%10;
        temp/=10;
    }

    
    return n==rev;
}