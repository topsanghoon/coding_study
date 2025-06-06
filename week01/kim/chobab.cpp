#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    int n,d,k,c;
    cin >> n >> d >>k >> c;
    vector<int> a = vector<int>(n); // 회전초밥 테이블
    queue<int> q; // 초밥 큐
    int chobab[3001] = {}; // 큐에 들어있는 초밥 종류 별 갯수
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int ans = 0; // 현재 큐에 들어있는 초밥 종류의 수 (큐에 2,3,3,4가 들어있으면 종류의 수는 2,3,4 3개개)
    int mx = 0; // ans의 최대값(정답)
    
    chobab[c]++; // 쿠폰 처리
    ans++;
    
    for(int i=0;i<k;i++){
        if(chobab[a[i]]==0){ // 해당하는 번호의 초밥이 큐에 들어있지 않으면
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
        if(chobab[qfront]==1){ // qfront번 초밥이 하나밖에 없으면
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