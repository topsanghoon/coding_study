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

    int cnt = 0; // 현재 큐에 들어있는 초밥 종류의 수 (큐에 2,3,3,4가 들어있으면 종류의 수는 [2,3,4] 3개)
    
    
    chobab[c]++; // 쿠폰 처리
    cnt++;
    
    for(int i=0;i<k;i++){
        if(chobab[a[i]]==0){ // 해당하는 번호의 초밥이 큐에 들어있지 않으면
            cnt++;
        }
        chobab[a[i]]++;
        q.push(a[i]);
    }

    int mx = cnt; // cnt의 최대값(정답)
    
    for(int i=0;i<n;i++){
        
        int qfront = q.front();

        if(chobab[qfront]==1){ // qfront번 초밥이 하나밖에 없으면
            cnt--;
        }
        q.pop();
        chobab[qfront]--;

        int idx = (i+k)%n;
        if(chobab[a[idx]]==0){
            cnt++;
        }
        chobab[a[idx]]++;
        q.push(a[idx]);

        if(mx < cnt){
            mx = cnt;
        }
    }
    
    cout<<mx<<'\n';
    return 0;
}

// https://jungol.co.kr/problem/2572