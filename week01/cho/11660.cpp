#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr1(N+1, vector<int>(N+1, 0));

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int num;
            cin >> num;
            arr1[i][j] = num + arr1[i-1][j] + arr1[i][j-1] - arr1[i-1][j-1];
        }
    }

    while(M--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int result = arr1[x2][y2] 
                   - arr1[x1-1][y2] 
                   - arr1[x2][y1-1] 
                   + arr1[x1-1][y1-1];
        
        cout << result << '\n';
    }

    return 0;
}
