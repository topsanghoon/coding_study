#include <stdio.h>
#include <math.h>
/*
재귀 함수로 하노이탑 구현
n개의 원판을 1번에서 3번으로 옮길 때

1. 1번에서 n-1개의 원판을 2번에 놓고, 
2. 1번의 마지막 원판을 3번으로 옮긴 뒤,
3. 2번의 원판을 3번으로 모두 옮기는 순서로 쌓아야함

이 원리를 재귀적으로 접근하여 문제를 풀었음
*/ 

void hanoii(int n, int s, int e, int tmp){ 

    if(n<=0) return;
    hanoii(n-1,s,tmp,e);
    printf("%d %d\n", s, e);
    hanoii(n-1,tmp,e,s);   
    
}


int main() {
    int n;
    scanf("%d ",&n);

    int cnt = (int)pow(2,n)-1;
    printf("%d\n", cnt);

    hanoii(n,1,3,2);
    return 0;
}