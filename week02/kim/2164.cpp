#include <iostream>
#include <deque>
using namespace std;

int main(){

    int n;
    cin >> n;
    deque<int> deq;
    for(int i=1;i<=n;i++){
        deq.push_back(i);
    }
    
    int ans;
    int cur = deq.front();
    while(deq.size()>1){
        deq.pop_front();
        cur = deq.front();
        deq.pop_front();
        deq.push_back(cur);
    }
    cout << cur << '\n';
    
    return 0;
}