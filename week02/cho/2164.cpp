#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    queue<int> arr;
    
    for(int i=1; i<=N; i++) {
        arr.push(i);
    }
    
    
    while(arr.size() > 1) {
        // 버리기
        arr.pop();             
        
        //뒤로 이동
        arr.push(arr.front());
        arr.pop();
    }
    
    cout << arr.front();
    return 0;
}