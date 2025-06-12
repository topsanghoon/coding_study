#include <iostream>
#include <queue>

using namespace std;

int main(){
 
    int n = 0;
    cin >> n;

    int dasom = 0;
    cin >> dasom;

    priority_queue <int> list;
    for(int i = 1; i < n; i++){
        int temp = 0;
        cin >> temp;
        list.push(temp);
    }

    int cnt = 0;
    while(!list.empty() && list.top() >= dasom){

        int temp = list.top();
        list.pop();
        list.push(--temp);
        cnt++;
        dasom++;
    }
    
    cout << cnt;
    return 0;
}