#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) return a > b; // 절댓값 같으면 더 작은 수 우선
        return abs(a) > abs(b);             // 절댓값 작은 수 우선
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, cmp> pq;

    for (int i = 0; i < N; i++) {
        int input_data;
        cin >> input_data;
        if (input_data == 0) {
            if (pq.empty()){
                cout << 0 << '\n';    
            } 
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } 
        else {
            pq.push(input_data);
        }
    }
    return 0;
}

//11286  못 풀어서 gpt 사용 .. 