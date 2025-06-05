#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin >> n >> m;
    
    vector<int> arr = vector<int>(n+1,0);
    vector<int> remains = vector<int>(m,0);
    int a;
    for(int i=1;i<=n;i++){
        cin >> a;
        arr[i] = (arr[i-1] + a)%m;       
    }
    for(int i=1;i<=n;i++){
        int remain = arr[i];
        remains[remain]++;
        
    }
    long long ans = remains[0];
    for(int i=0; i<m; i++){
        if(remains[i]>1){
            ans += ((long long)remains[i]*(remains[i]-1))/2;
        }
    }
    cout<<ans<<'\n';
    return 0;
}

//main 브랜치
//kim 브랜치