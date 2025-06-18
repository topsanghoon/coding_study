//15:06 15:13
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n = 0;
    cin >> n;

    queue <int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    int cnt = 0;
    while(q.size() != 1){
        if(cnt == 0){   //버릴때
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }

        cnt = (cnt + 1) % 2;
    }

    cout << q.front();
}