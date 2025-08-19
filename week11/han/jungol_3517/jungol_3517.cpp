#include <iostream>
#include <vector>

using namespace std;

// https://jungol.co.kr/problem/3517
// 이진탐색

long long N;
long long Q;
vector<long long> arr;
vector<long long> answer;
long long binarySearch(long long low, long long high, long long target){
    long long mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(void){
    cin >> N;
    for(int i = 0; i < N; i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> Q;

    for(int i = 0; i < Q; i++){
        long long temp;
        cin >> temp;
        answer.push_back(binarySearch(0, arr.size()-1,temp));
    }

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
}