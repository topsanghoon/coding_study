#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://jungol.co.kr/problem/5461
// 숫자구슬

int N, M;
vector<long long> arr;
vector<long long> answer;

bool canGrouping(long long allowedValue){
    long long groupcount = 1;
    long long currentSum = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > allowedValue) return false;
        if(currentSum + arr[i] > allowedValue){
            groupcount += 1;
            currentSum = arr[i];
        }
        else{
            currentSum += arr[i];
        }
    }
    return groupcount <= M;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    long long sum = 0;
    for(int i = 0; i < N; i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
        sum += temp;
    }

    long long left = *max_element(arr.begin(), arr.end());
    long long right = sum;

    while(left <= right){
        long long mid = (left + right) / 2;
        if(canGrouping(mid)){
            answer.push_back(mid);
            right = mid - 1;
        }
        else left = mid + 1;
    }

    // for(int i = 0; i < answer.size(); i++){
    //     cout << answer[i] << "\n";
    // }

    cout << *min_element(answer.begin(), answer.end());

}