#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    int n,d,k,c;
    cin >> n >> d >>k >> c;
    vector<int> a = vector<int>(n);
    queue<int> q;
    int chobab[3001] = {};
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int ans = 0;
    int mx = 0;
    
    chobab[c]++;
    ans++;
    
    for(int i=0;i<k;i++){
        if(chobab[a[i]]==0){
            ans++;
        }
        chobab[a[i]]++;
        q.push(a[i]);
    }
    if(mx < ans){
        mx = ans;
    }
    for(int i=0;i<n;i++){
        
        int qfront = q.front();
        if(chobab[qfront]==1){
            ans--;
        }
        q.pop();
        chobab[qfront]--;
        int idx = (i+k)%n;
        if(chobab[a[idx]]==0){
            ans++;
        }
        chobab[a[idx]]++;
        q.push(a[idx]);
        if(mx < ans){
            mx = ans;
        }
    }
    
    cout<<mx<<'\n';
    return 0;
}

// https://jungol.co.kr/problem/2572