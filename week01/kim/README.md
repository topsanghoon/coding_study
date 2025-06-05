# Week01 정리

## 1. int 범위 간과

### 문제 10986

```
c++
    long long ans = remains[0];
    for(int i=0; i<m; i++){
        if(remains[i]>1){
            ans += ((long long)remains[i]*(remains[i]-1))/2;
        }
    }
```
정답의 범위가 int형의 범위를 넘어갈 수 있다는 것을 고려하지 않음.

ans를 long long 형으로 선언, 관련 연산에 (long long) 형변환을 사용하여 문제 해결.