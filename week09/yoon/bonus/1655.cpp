#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue <int> left;
    priority_queue <int, vector<int>, greater<int>> right;
    int left_n = 0, right_n = 0;
    int first;
    cin >> first;
    left.push(first);
    left_n++;
    cout << left.top() << '\n';
    for(int i = 1; i < n; i++){
        int cur;
        cin >> cur;

        if(left.top() <= cur) {
            right.push(cur);
            right_n++;
        }
        else {
            left.push(cur);
            left_n++;
        }

        int diff = left_n - right_n;
        if(diff < -1){//오른쪽에서 왼쪽으로 한개 이동
            left.push(right.top());
            left_n++;
            right.pop();
            right_n--;
        }
        else if(diff > 1){
            right.push(left.top());
            right_n++;
            left.pop();
            left_n--;
        }

        diff = left_n - right_n;
        if(diff == 1 || diff == 0) cout << left.top() << '\n';
        else if(diff == -1) cout << right.top() << '\n';

    }
}