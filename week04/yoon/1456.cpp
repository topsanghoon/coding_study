#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector <bool> priority;
void priority_map(int m){    //소수를 구하는 함수
    priority.resize(m, 1);

    priority[0] = false, priority[1] = false;
    for(int i = 2; i*i <m; i++){
        if(priority[i] == false) continue;
        for(int j = i * i; j < m; j += i){
              priority[j] = false;
        }
    }
}

int main(){
    long long a, b;
    cin >> a >>  b;

    int end = (int)sqrt(b) + 2;   //소수가 가질 수 있는 범위는 오른쪽 범위의 Sqrt 정도
    
    priority_map(end);

    int result = 0;
    for(long long i = 2; i < end; i++){
        if(priority[i] == 1){
            for(long long j = 2; 1; j++){
                if(pow(i, j) > b) break;      // 소수들의 제곱들을 순회하면서 비교
                if(pow(i, j) >= a) result++;
            }
        }
    }

    cout << result;
    
    return 0;
}