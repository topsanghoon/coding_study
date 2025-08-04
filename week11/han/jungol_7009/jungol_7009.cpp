#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://jungol.co.kr/problem/7009
// 도둑 잡아라

int N, Q;
vector<long long> arr;
vector<long long> answer;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < Q; i++){
        long long temp;
        cin >> temp;
        if(binary_search(arr.begin(), arr.end(), temp) == false) answer.push_back(temp);
    }

    if(answer.size() == 0) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < answer.size(); i++) cout << answer[i] << " ";
}