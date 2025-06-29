#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
  0 1 2 3 4 5 6
0 □ □
1 □ ■ □
2 □ ■ ■ □
3 □ ■ ■ ■ □
4 □ ■ ■ ■ ■ □
5 □ ■ ■ ■ ■ ■ □

■ 는 데이터를 저장할 칸
□ 는 코드 간결화를 위해 0으로 저장해둔 칸

n번 줄의 데이터는 자기 바로 위(j)와 왼쪽 위(j-1) 중에서 더 큰 값을 선택할 수 있음
이를 통해 항상 더 큰값을 저장,  마지막 줄에서 가장 큰 값이 정답
*/

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> DP(n+1,vector<int> (n+2 , 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            int temp;
            cin >> temp;
            DP[i][j] = max(DP[i-1][j], DP[i-1][j-1]) + temp;
        }
    }

    cout << *max_element(DP[n].begin(), DP[n].end());

    return 0;
}