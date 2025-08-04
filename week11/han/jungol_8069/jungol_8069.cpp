#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// https://jungol.co.kr/problem/8069
// 이진탐색(라이브러리 사용법)

int N, Q;
vector<int> arr;
vector<int> answer;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for(int i = 0; i < Q; i++){
        int temp;
        cin >> temp;
        auto it = lower_bound(arr.begin(), arr.end(), temp);
        if(it == arr.begin()) {
            answer.push_back(*it);
            continue;
        }
        if(it == arr.end()){
            answer.push_back(*(it-1));
            continue;
        } 
        int upper = *it;
        int lower = *(it-1);
        if(abs(upper - temp) >= abs(lower-temp)) answer.push_back(lower);
        else answer.push_back(upper); 
    }

    for(int i = 0; i < answer.size(); i++) cout << answer[i] << "\n";

    return 0;
}