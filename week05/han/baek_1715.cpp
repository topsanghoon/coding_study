#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// https://www.acmicpc.net/problem/1715
// 카드 정렬하기
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;
    
    vector<int> array(count,0);
    priority_queue<int,vector<int>,greater<int>> pQueue;
    for(int i = 0; i<count; i++){
        cin >> array[i];
        pQueue.push(array[i]);
    }
    
    int tempSum = 0;
    int tempFirst = 0;
    int tempSecond = 0;
    int answer = 0;
    for(int i =0; i<count-1; i++){
        tempFirst = pQueue.top();
        pQueue.pop();
        tempSecond = pQueue.top();
        pQueue.pop();
        tempSum = tempFirst + tempSecond;
        answer += tempSum;
        pQueue.push(tempSum);
    }
    cout << answer;
}