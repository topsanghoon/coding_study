//https://www.acmicpc.net/problem/20055
#include <iostream>
#include <deque>
using namespace std;

deque<int> d_top, d_bottom;
deque<int> robots;
int N, K;

void print_tray(){
    for(int i=0; i<N; i++) cout << d_top[i] << " ";
    cout << '\n';
    for(int i=N-1; i>=0; i--) cout << d_bottom[i] << " ";
    cout << '\n';
}

void move_tray(){
    d_bottom.push_back(d_top.back());
    d_top.pop_back();
    d_top.push_front(d_bottom.front());
    d_bottom.pop_front();

    
    robots.push_front(0); 
    robots.pop_back();
    robots[N-1] = 0; 
}

void move_robot(){
    for(int i=N-2; i>=0; i--){
        if(robots[i] && !robots[i+1] && d_top[i+1]>=1){
            robots[i] = 0;
            robots[i+1] = 1;
            d_top[i+1]--;
        }
    }
    robots[N-1] = 0;
}

void add_robot(){
    if(d_top[0]>=1 && robots[0]==0){
        robots[0] = 1;
        d_top[0]--;
    }
}

int count_zero(){
    int cnt=0;
    for(int i=0; i<N; i++) if(d_top[i]==0) cnt++;
    for(int i=0; i<N; i++) if(d_bottom[i]==0) cnt++;
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    robots.resize(N,0);
    for(int i=0; i<N; i++){
        int tmp; 
        cin >> tmp;
        d_top.push_back(tmp);
    }
    for(int i=0; i<N; i++){
        int tmp; 
        cin >> tmp;
        d_bottom.push_front(tmp);
    }

    int step=0;
    while(count_zero() < K){
        step++;
        move_tray();
        
        move_robot();
        
        add_robot();
        
    }
    cout << step << '\n';
    return 0;
}
