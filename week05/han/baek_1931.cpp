#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/1931
// 회의실 배정
struct compare{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int main(void){
    int count;
    cin >> count;
    int tFirst;
    int tSecond;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
    for(int i =0; i<count; i++){
        cin >> tFirst >> tSecond;
        pq.push(make_pair(tFirst,tSecond));
    }

    pair<int,int> current = pq.top();
    pq.pop();
    int answer = 1;
    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        // cout << "현재: " << temp.first << " " << temp.second << "\n";
        if(current.second <= temp.first){
            answer += 1;
            current = temp;
        }
        pq.pop();
    }
    cout << answer;
}