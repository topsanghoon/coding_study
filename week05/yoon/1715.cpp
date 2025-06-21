#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    int n;
    cin >> n;

    priority_queue <int, vector <int>, greater<int>> cards;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        cards.push(temp);
    }

    int ans = 0;

    // 10 20 30 40 50
    while(cards.size() != 1){
        int sum = 0;
        sum = sum + cards.top();
        cards.pop();
        sum = sum + cards.top();
        cards.pop();

        ans += sum;
        cards.push(sum);
    }

    cout << ans;

    return 0;
}