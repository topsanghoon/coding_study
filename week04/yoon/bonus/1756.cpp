#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int d, n;
    cin >> d >> n;

    stack <int> oven;
    while(d--){
        int temp = 0;
        cin >> temp;
        if(!oven.empty() && oven.top() < temp) temp = oven.top();
        oven.push(temp);
    }

    while(n--){
        int temp = 0;
        cin >> temp;

        while(!oven.empty() && oven.top() < temp){
            oven.pop();
        }
        if(oven.empty()){
            cout << 0;
            return 0;
        }
        oven.pop();
    }

    cout << oven.size() + 1;

    return 0;
}