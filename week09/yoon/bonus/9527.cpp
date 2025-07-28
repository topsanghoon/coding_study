#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector <long long> pre_cal;

void search(long long num){
    int bits = (int)log2(num);
    
    for (int i = 1; i <= bits; i++) {
        pre_cal[i] = (1LL << (i - 1)) + pre_cal[i - 1] * 2;

    }
}

long long find_1(long long num) {
    if (num == 0) return 0;

    int bits = (int)log2(num);  // 가장 높은 비트 위치
    long long result = 0;

    for (int i = bits; i >= 0; i--) {
        long long pow2 = (1LL << i);
        if (num >= pow2) {
            result += pre_cal[i];         // 하위 길이까지 누적합
            result += (num - pow2 + 1);   // 현재 비트에서 1이 추가로 나오는 수
            num -= pow2;                  // 다음으로 넘어감
        }
        
    }

    return result;
}

int main() {
    long long start, end;
    cin >> start >> end;

    pre_cal.resize(61);
    pre_cal[0] = 0; 

    search(end);

    cout << find_1(end) - find_1(start - 1) << '\n';

    return 0;
}