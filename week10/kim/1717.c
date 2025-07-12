#include <stdio.h>
#define MAX 1000001

int arr[MAX];

int find(int x){ // 루트노드를 찾아줌
    if(arr[x]<0) return x;
    int root = find(arr[x]); // 부모 노드를 간접으로 참조하고 있으면
    arr[x] = root; // 루트 노드로 통일시켜줌
    return root;
}

int is_equal_root(int a, int b){ // 루트노드가 같은지 확인
    return (find(a)==find(b));
}

void swap(int* a, int* b){ // a와 b를 서로 바꿈
    int* tmp = a;
    a = b;
    b = tmp;
}

void union_arr(int a, int b){
    a = find(a); //a 루트 찾음
    b = find(b); //b 루트 찾음

    if(a==b) return ; // 같으면 종료
    
    if(arr[a]<arr[b]){ // 더 큰(깊은) 노드에 다른 노드가 합쳐지는 방식
        swap(&a, &b);
    }
    
    if(arr[a]==arr[b]){ // 같은 깊이의 노드라면
        arr[a]--; // 노드 깊이가 1 증가됨(최적화)
    }
    arr[b] = a; // 노드를 합침
}

int main() {
    int n,m;
    scanf("%d %d ",&n, &m);
    
    for(int i=0;i<=n;i++){
        arr[i] = -1;
    }
    int cmd,a,b;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&cmd,&a,&b);
        if(cmd==1){
            if(is_equal_root(a,b)) printf("YES\n");
            else printf("NO\n");
            continue;
        }
        union_arr(a,b);
    }
    
    return 0;
}