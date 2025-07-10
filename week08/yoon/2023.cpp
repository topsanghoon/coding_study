#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
bool is_prime(int num) {    //소수인지 판별하는 함수
    if(num < 2) return false;
    for(int i = 2; i <= sqrt(num); ++i){
        if(num % i == 0) return false;
    }
    return true;
}

void dfs(int depth, int prim_num){
    if(depth == n){    
    cout << prim_num << endl;
    return;
    }
    for(int i = 0; i <= 9; i++){
        int next_prim = prim_num * 10 + i ; 
        if(is_prime(next_prim)) dfs(depth + 1 , next_prim); //소수일때만 dfs 더 진행
    }

    return;
}


int main() {
    cin >> n;
    int n1_prime[4] = {2, 3, 5, 7}; //초기 설정
    if(n<1){
        for(int prim :n1_prime) cout << prim << endl; //예외처리
    }
    else{
        for(int prim :n1_prime) //2, 3, 5, 7에서 하나씩 시작
            dfs(1, prim);//깊이 , 이전 소수값
    }

    return 0;
}