#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    vector<bool> nums = vector<bool>(m+1,true);
    nums[0] = false;
    nums[1] = false;
    for(int i=2;i<=m;i++){
        if(!nums[i]) continue;
        if(i>=n){
            cout<< i <<'\n';
        }
        int idx = 1;
        while((i*++idx)<=m){
            nums[i*idx] = false;
        }
    }
    
}