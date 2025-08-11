//https://jungol.co.kr/problem/1929?cursor=OCw0LDM%3D
#include <iostream>
#include <queue>
using namespace std;
int main() {
    int N;
    cin>>N;
    //오름차순으로 우선순위 큐를 선언 , <데이터 타임(pair,int) , 컨테이너 종류(vector,deque) , compare(greater, less)>
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i=0;i<N;i++) {
        int tmp;
        cin>>tmp;
        pq.push(tmp);
    }
    
    // while(!pq.empty()){
    //     int tmp=pq.top(); pq.pop();
    //     cout<<tmp<<" ";
    // }
    long long res_sum=0;
    while(!(pq.size()==1)){
        int temp1=pq.top(); pq.pop();
        int temp2=pq.top(); pq.pop();
        long long tmp_sum=temp1+temp2;
        res_sum += tmp_sum;
        //cout<<"temp1:"<<temp1<<" temp2:"<<temp2<<" tmp_sum:"<<tmp_sum<<" res_sum:"<<res_sum<<'\n';

        pq.push(tmp_sum);
    }
    cout<<res_sum;
    return 0;
}