#include <iostream>
#include <vector>

using namespace std;

// 부녀회장이 될테야
// https://www.acmicpc.net/problem/2775
int apart[14+1][14+1] = {0,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int,int>> question;

    int N;
    cin >> N;

    for(int i = 1; i <= 14; i++){
        apart[0][i] = i;
    }

    for(int i = 1; i < 15; i++){
        for(int j = 1; j <= 14; j++){
            if(j == 1) apart[i][j] = 1;
            else apart[i][j] = apart[i][j-1] + apart[i-1][j];
        }
    }

    for(int i = 0; i < N; i++){
        int floor;
        int room;
        cin >> floor;
        cin >> room;
        question.push_back(make_pair(floor, room));
    }

    for(int i = 0; i < (int)question.size(); i++){
        cout << apart[question[i].first][question[i].second] << "\n";
    }

}