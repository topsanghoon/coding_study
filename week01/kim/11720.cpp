#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    char a;
    for(int i=0;i<n;i++){
        cin>>a;
        ans += a-'0';
    }

    cout<<ans<<'\n';
    
    return 0;
}