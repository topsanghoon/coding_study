#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin >> n >> m;
    string str;
    unordered_map<string,int> strmap;
    
    for(int i=0;i<n;i++){
        cin >> str;
        strmap[str] = 1;
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        cin >> str;
        if(strmap[str]==1){
            ans++;
        }
    }
    cout << ans << '\n';
    

    
    return 0;
}

