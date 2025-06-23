#include <iostream>
#include <queue>
using namespace std;

// 비교 연산자
struct cmp {
    bool operator()(const int a, const int b) {
        // 오름차순 정렬: 작은 값이 top에 오도록
        return a > b;
    }
};

int main() {
    int N;
    cin >> N;
    priority_queue<int,vector<int>, cmp> pq;
    
    int total=0;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        pq.push(temp);
    }
    int na=0;
    int nb=0;
    int tmp=0;
    while(pq.size() !=1){
        na=pq.top();
        pq.pop();
        nb=pq.top();
        pq.pop();

        tmp= na+nb;
        pq.push(tmp);
        total+=tmp;
        
    }
    cout<<total;
    return 0;
}