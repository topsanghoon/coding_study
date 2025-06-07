#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main(){

    int n;
    cin >> n;

    // pair을 이용하여 절대값과 부호를 저장
    //절대값을 오름차순으로 정렬
    //절대값이 같은 경우 부호가 -인것을 먼저 저장
    priority_queue<pair<int,int>> pq; 

    int a;
    for(int i=0;i<n;i++){

        cin >> a;
        if(a==0){
            if(pq.empty()){
                cout << 0 << '\n';
                continue;
            }
            pair<int,int> top = pq.top();
            cout << (top.first*top.second)<< '\n'; 
            pq.pop();
            continue;
        }
        pq.push(make_pair(-abs(a),-a/abs(a))); // 우선순위 큐 오름차순 정렬을 위해 부호를 -로 저장
            
    }
    
    return 0;
}

//숫자 문자 0