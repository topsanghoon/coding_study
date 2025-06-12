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


## 2. 잘못된 문제풀이 방법

### 문제 2567

```
c++
int getPerimeter(){
    
    int ny[4] = {1,-1,0,0};
    int nx[4] = {0,0,1,-1};
    int perimeter = 0;

    for(int i=1;i<=100;i++){
        for(int ii=1;ii<=100;ii++){
            
            if(arr[i][ii]==0) continue;
            for(int iii=0;iii<4;iii++){
                int next_y = i+ny[iii];
                int next_x = ii+nx[iii];

                if(arr[next_y][next_x]==0){
                    perimeter++;
                } 
            }  
        }
    }
    return perimeter;
}

```
점 주위 상하좌우 4방향을 판단하여 문제를 해결해야하는데
대각선방향 까지 8방향으로 문제를 해결하려다 문제 풀이에 어려움을 겼었습니다.

