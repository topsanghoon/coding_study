#include <stdio.h>
#define MAX 201
int arr[MAX] = {};

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

    if(a==b) return;
    
    if(arr[b]<arr[a]){
        swap(&a, &b);
    }
    
    if(arr[a]==arr[b]){
        arr[a]--;
    }
    
    arr[b] = a;
}
int is_equal_root(int a, int b){
    return (find(a)==find(b));
}

int main() {
    int n,m;
    scanf("%d ",&n);
    scanf("%d ",&m);

    int num;
    for(int i=1;i<=n;i++){
        arr[i]=-1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d ",&num);
            if(num==1){
                union_arr(i,j);
            }
        }
    }
    int start,end;
    scanf("%d ",&start);
    for(int i=2;i<=m;i++){
        scanf("%d ",&end);
        if(!is_equal_root(start,end)){
            printf("NO\n");
            return 0;
        }
        start = end;
    }

    printf("YES\n");
    return 0;
}