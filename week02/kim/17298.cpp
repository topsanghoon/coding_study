#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr = vector<int>(n,-1);
    stack<pair<int,int>> stk; // 저장된 수와 인덱스를 배열하는 스택 생성 
    int a;
    for(int i=0; i<n; i++){
        cin >> a; // 숫자를 입력받음
        while(!stk.empty() && stk.top().first<a){ // 스택에 저장된 수 보다 큰 수(오큰수)가 나타나면
            arr[stk.top().second] = a; // 인덱스에 해당하는 위치에 오큰수 저장 및 스택 pop
            stk.pop();
        }
        stk.push(make_pair(a,i)); // 인덱스와 함게 스택 push
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    
    return 0;
}