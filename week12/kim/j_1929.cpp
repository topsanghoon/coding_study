#include <iostream>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<>> pq;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        pq.push(a);
    }

    long long ans = 0;
    while(pq.size()>1){
        int fs = pq.top();
        pq.pop();
        int sd = pq.top();
        pq.pop();
        ans+= (long long)(fs+sd);
        pq.push((long long)(fs+sd));
    }
    cout << ans;

    return 0;
}