#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct compare{
    bool operator()(vector<int> a, vector<int> b){
        if(a[1]==b[1]) return a[0]>b[0];
        return a[1]>b[1];
    }
};

priority_queue<vector<int>, vector<vector<int>>, compare> pq;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    for(vector<int> target : targets){
        pq.push(target);
    }
    int cur = 0;
    while(!pq.empty()){
        vector<int> pqtop = pq.top();
        if(pqtop[0] < cur) {
            pq.pop();
            continue;
        }
        cout << pqtop[0]<<" "<<pqtop[1]<<'\n';
        cur = pqtop[1];
        answer++;
        pq.pop();
    }
    return answer;
}