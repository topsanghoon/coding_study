#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin >> n >> m;
    

    vector<vector<int>> arr(n+1,vector<int>(n+1,0));

    int a;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a;
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + a;
        }
    }
    int x1,y1,x2,y2;
    
    for(int i=0;i<m;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1] << '\n';
    }
    return 0;
}