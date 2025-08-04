#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://jungol.co.kr/problem/5804
// 환경부의 나무 심기 프로젝트

int N, C;
vector<int> arr;

int returnCnt(int num){
    int cnt = 1;
    int last = arr[0];
    for(int i = 1; i < N; i++){
        if(last + num > arr[i]) continue;
        last = arr[i];
        cnt++;
    }
    return cnt;
}

int main(void){
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    } 

    sort(arr.begin(), arr.end());

    int low = 1;
    int high = arr[arr.size()-1] - arr[0];

    while(low <= high){
        int mid = (low+high) / 2;
        int mid_res = returnCnt(mid);
        if(mid_res < C) high = mid - 1;
        else low = mid + 1;
    }
    cout << low - 1;
    return 0;
}