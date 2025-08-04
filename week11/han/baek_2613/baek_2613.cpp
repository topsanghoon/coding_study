#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://jungol.co.kr/problem/5461
// 숫자구슬

int N, M;
vector<long long> arr;
vector<long long> answer;
vector<int> answerIndex;

void findGroup(long long target){
    long long currentSum = 0;
    int count = 0;
    int leftGroup = M;
    for(int i = 0; i < (int)arr.size(); i++){
        if(currentSum + arr[i] > target || leftGroup > ((int)arr.size() - i)){
            currentSum = arr[i];
            answerIndex.push_back(count);
            count = 1;
            leftGroup -= 1;
        }
        else{
            currentSum += arr[i];
            count += 1;
        }
    }
    answerIndex.push_back(count);
}

bool canGrouping(long long allowedValue){
    long long groupcount = 1;
    long long currentSum = 0;
    for(int i = 0; i < (int)arr.size(); i++){
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
    int finalAnswer = *min_element(answer.begin(), answer.end());
    cout << finalAnswer << "\n";

    findGroup(finalAnswer);
    for(int i = 0; i < (int)answerIndex.size(); i++){
        cout << answerIndex[i] << " ";
    }
}