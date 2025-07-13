#include <stdio.h>
#define MAX 51

int party[MAX][MAX] = {};
int arr[MAX] = {};
int known[MAX] = {};

void swap(int* a, int* b){
    int* tmp = a;
    a = b;
    b = tmp;
}

int find(int x){
    if(arr[x]<0) return x;
    int root = find(arr[x]);
    arr[x] = root;
    return root;
}

void union_arr(int a, int b){
    a = find(a);
    b = find(b);

    if(a==b){
        return ;
    }

    if(arr[b]<arr[a]){
        swap(&a, &b);
    }

    if(arr[a]==arr[b]){
        arr[a]--;
    }
    if(known[b]==1){ // b가 지민이의 진실을 알면
        known[a]=1; // 유니온 루트도 진실을 알게된다.
    }
    arr[b] = a;
    
}

int main() {

    int n,m;
    scanf("%d %d ",&n,&m);
    for(int i=1;i<=n;i++){
        arr[i] = -1;
    }
    int cnt,input;
    scanf("%d ",&cnt);
    for(int i=1;i<=cnt;i++){
        scanf("%d ",&input); 
        known[input] = 1;
    }

    for(int i=1;i<=m;i++){
        scanf("%d ",&party[i][0]); // 0번째 인덱스에는 파티참여인원을 
        scanf("%d ",&party[i][1]);
        
        for(int j=2;j<=party[i][0];j++){
            scanf("%d ",&party[i][j]);
            union_arr(party[i][1],party[i][j]);
        }
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        
        if(known[find(party[i][1])]==0) ans++;
        // known[party[i][1]]을 안쓰는 이유
        // party[i][1] 자체가 누구의 자식노드일 수 있
    }
    printf("%d\n",ans);
    
    return 0;
}