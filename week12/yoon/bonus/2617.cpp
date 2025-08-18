#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> BigToSmall(N+1, vector<int>(N+1, 0));

    for(int i = 0; i < M; i++){
        int big, small;
        cin >> big >> small;
        BigToSmall[big][small] = 1; 
    }

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(BigToSmall[i][k] && BigToSmall[k][j]){
                    BigToSmall[i][j] = 1;
                }
            }
        }
    }

    vector<int> smaller(N+1, 0), bigger(N+1, 0);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(BigToSmall[i][j]) smaller[i]++;
            if(BigToSmall[j][i]) bigger[i]++;  
        }
    }


    // for(int i = 1; i <= N; i++) cout << smaller[i] << " ";
    // cout << "\n";
    // for(int i = 1; i <= N; i++) cout << bigger[i] << " ";
    // cout << "\n";


    int answer = 0;
    int ref = (N+1)/2;
    for(int i = 1; i <= N; i++){
        if(smaller[i] >= ref || bigger[i] >= ref) answer++;
    }
    cout << answer << "\n";

    return 0;
}
