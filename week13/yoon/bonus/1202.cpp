#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<pair<int ,int>> jewel;
    for(int i = 0; i < N; i++){
        int M, V;
        cin >> M >> V;

        jewel.push_back({M, V});
    }

    vector<int> bags(K);
    for(int i = 0; i < K; i++) cin >> bags[i];

    sort(bags.begin(), bags.end());
    sort(jewel.begin(), jewel.end());


    int idx = 0;
    long long answer = 0;
    priority_queue<int> q;
    for(int bag : bags){
        while(idx < N && bag >= jewel[idx].first){

            q.push(jewel[idx].second);
            idx++;
        }
        if(!q.empty()){
            answer += q.top();
            q.pop();
        }
    }

    cout << answer;

    return 0;
}