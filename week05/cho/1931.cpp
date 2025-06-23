#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int x;
    int y;  
};

struct cmp{
    bool operator()(const Node& a, const Node& b){
        if(a.y == b.y) return a.x>b.x;
        return a.y>b.y;
    }
};
int main() {
    int N;
    cin>>N;
    priority_queue<Node,vector<Node>,cmp> pq;
    
    int x=0,y=0;
    for(int i=0;i<N;i++){
        cin>>x>>y;
        pq.push({x,y});
    }
    int nx=0;
    int count=0;
    int ny=0;
    
    for(int i=0;i<N;i++){
        Node t=pq.top();
        if(t.x >= ny){ // 작은 요소 셋을 없애기 -> 남은 큐의 갯수가 답이다. 
            nx=t.x;
            ny=t.y;
            count++;
            // cout<<"nx:  "<<nx<<"ny:  "<<ny<<" 카운트: "<<count<<'\n';
        }
        pq.pop();
        
    }
    
    // while (!pq.empty()) {
    //     Node t = pq.top();
    //     cout << "x: " << t.x << ", y: " << t.y << endl;
    //     pq.pop();
    // }
    cout<<count;
    return 0;
}