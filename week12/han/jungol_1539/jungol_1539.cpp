#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 가장높은탑쌓기
// https://jungol.co.kr/problem/1539

struct _block{
    int num;
    int wide;
    int height;
    int weight;
}typedef block;

int N;
vector<block> arr;
int dp[100] = {0,};
vector<vector<int>> answerDp(100,vector<int>(0));

int main(void){
    cin >> N;
    for(int i = 0; i < N; i++){
        int tempWide;
        int tempHeight;
        int tempWeight;
        cin >> tempWide >> tempHeight >> tempWeight;
        arr.push_back({i+1, tempWide, tempHeight, tempWeight});
    }

    sort(arr.begin(), arr.end(), [](const block &a, const block &b){
            if(a.wide == b.wide) return a.weight > b.weight;
            return a.wide > b.wide;
        }
    );

    // for(int i = 0; i < N; i++){
    //     cout << arr[i].wide << " " << arr[i].height << " " << arr[i].weight << "\n";
    // }

    dp[N-1] = arr[N-1].height;
    answerDp[N-1].push_back(N-1);

    for(int i = N-2; i >= 0; i--){
        int tempMax = 0;
        int tempMaxIndex = -1;
        for(int j = N-1; j > i; j--){
            if(arr[i].weight > arr[j].weight && tempMax < dp[j]){
                tempMax = dp[j];
                tempMaxIndex = j;
            }
        }
        dp[i] = arr[i].height + tempMax;
        answerDp[i].push_back(i);
        if(tempMaxIndex == -1) continue;
        for(int k = 0; k < (int)answerDp[tempMaxIndex].size(); k++){
            answerDp[i].push_back(answerDp[tempMaxIndex][k]);
        }
    }

    // for(int i = 0; i < N; i++){
    //     cout << "i: " << i << " dp[]: " << dp[i] << "\n";
    //     for(int j = 0; j < answerDp[i].size(); j++){
    //         cout << answerDp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int answerIndex = -1;
    int answerMax = 0;
    for(int i = 0; i < N-1; i++){
        if(answerMax < dp[i]) {
            answerMax = dp[i];
            answerIndex = i;
        }
    }
    cout << answerDp[answerIndex].size() << "\n";
    for(int i = answerDp[answerIndex].size()-1; i >= 0; i--){
        cout << arr[answerDp[answerIndex][i]].num << "\n";
    }
}