#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    int mn = INT_MAX;
    cin >> n;
    vector<int> a(n,0);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int st = 0;
    int ed  = n-1;
    int mnst = st;
    int mned = ed;
    
    while(st<ed){
        if(mn > abs(a[ed]+a[st])){
            mnst = st;
            mned = ed;
            mn = abs(a[ed]+a[st]);
        }
        if(abs(a[ed-1]+a[st])<abs(a[ed]+a[st+1])){
            ed--;
            continue;
        }
        st++;
    }
    cout<<a[mnst]<<' '<<a[mned]<<'\n';
    
    return 0;  
}