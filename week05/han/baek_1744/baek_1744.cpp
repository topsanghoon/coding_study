#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 수 묶기
// https://www.acmicpc.net/problem/1744
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int N;
    cin >> N;

    int temp;
    for(int i = 0; i < N; i++){
        cin >> temp;
        if(temp > 0) maxHeap.push(temp);
        else minHeap.push(temp);
    }

    int maxSize = maxHeap.size();
    int minSize = minHeap.size();

    int maxSum = 0;
    
    if(maxSize != 0){
        for(int i = 0; i < maxSize/2; i++){
            int maxFirst = maxHeap.top();
            maxHeap.pop();
            int maxSecond = maxHeap.top();
            maxHeap.pop();

            // 1일 때는 수끼리 곱하지 않고 더한다.
            if(maxFirst == 1 || maxSecond == 1) maxSum += maxFirst + maxSecond;
            else maxSum += maxFirst * maxSecond;
        }
        if(!maxHeap.empty()){
            maxSum += maxHeap.top();
        }
    }

    int minSum = 0;
    if(minSize != 0){
        for(int i = 0; i < minSize/2; i++){
            int minFirst = minHeap.top();
            minHeap.pop();
            int minSecond = minHeap.top();
            minHeap.pop();
            // 음수 * 음수는 양수임을 이용해 최댓값을 만든다.
            // minFirst와 minSecond에 0이 있더라도 0 * 음수는 0이기 때문에 오히려 최댓값을 만들때 도움이 된다.
            // 이를 이용한다.
            minSum += minFirst * minSecond;
        }
        if(!minHeap.empty()){
            // 최소힙의 요소 개수가 홀수이면 음수 또는 0 일텐데 그거에 상관없이 더한다.
            minSum += minHeap.top();
        }
    }
    cout << maxSum + minSum;
}