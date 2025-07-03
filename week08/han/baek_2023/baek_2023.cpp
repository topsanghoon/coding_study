#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/2023
// 신기한 소수
vector<int> answer;
bool isPrime(int num){
    for(int i = 2; i <= int(sqrt(num)); i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

void dfs(int num, int N, int n){
    if(N==1) {
        answer.push_back(num);
        return;
    }
    if(n==N) return;
    
    for(int i = 0; i <= 9; i++){
        int temp = num*10 + i;
        bool check = isPrime(temp);
        
        if(check) {
            if(n == N-1) answer.push_back(temp);
            dfs(temp, N, n+1);
        }
    }
    return;
}

int main(void){
    int N;
    cin >> N;

    dfs(2,N,1);
    dfs(3,N,1);
    dfs(5,N,1);
    dfs(7,N,1);

    for(int i = 0; i < (int)answer.size(); i++){
        cout << answer[i] << "\n";
    }

    return 0;
}