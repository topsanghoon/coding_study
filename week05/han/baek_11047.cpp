#include <iostream>
#include <vector>
using namespace std;

// 동전 0
// https://www.acmicpc.net/problem/11047
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count, price;
    cin >> count >> price;
    vector<int> array(count,0);
    
    for(int i = 0; i< count; i++){
        cin >> array[i];
    }

    int answer = 0;
    int remain = price;
    for(int i = count-1; i >= 0; i--){
        answer +=  remain/array[i];
        remain = remain % array[i];
        if(remain == 0) break;
    }
    cout << answer;
}