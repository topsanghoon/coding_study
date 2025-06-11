#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num,s,e;
    int ans = 0;
    priority_queue<pair<int,int>> pre;
    priority_queue<int> cur;
    
    for(int i=0;i<n;i++){
        cin >> num >> s >> e;
        pre.push(make_pair(-s,-e));
    }
    while(!pre.empty()){
        int st = -pre.top().first;
        int et = -pre.top().second;
        pre.pop();
        while(!cur.empty() && -cur.top() <= st){
            cur.pop();
        }
        cur.push(-et);
        if(ans < cur.size()){
            ans = cur.size();
        }
    }
    cout<<ans<<'\n';
    return 0;
}