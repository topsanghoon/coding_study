#include <iostream>
#include <algorithm>
using namespace std;

// 1로 만들기
// https://www.acmicpc.net/problem/1463
int arr[1000000+1] = {0,};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for(int i = 4; i <= N; i++){
        arr[i] = arr[i-1]+1;
        if(i%3 == 0){
            arr[i] = min(arr[i],arr[i/3]+1);
        }
        if(i%2==0){
            arr[i] = min(arr[i],arr[i/2]+1);
        }
    }

    cout << arr[N];
}