#include <stdio.h>
#include <stdlib.h> // qsort 이용

#define MAX_ARR_SIZE 1000001

int compare(const void* a, const void* b){
    return (*(int*)b - *(int*)a);
}

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    
    int arr[MAX_ARR_SIZE] = {};
    
    for(int i=0;i<n;i++){
        scanf("%d ",&arr[i]);
    }

    qsort(arr,n,sizeof(int),compare);
    
    int cnt = 0;

    for(int i=0;i<n;i++){
        while(arr[i]<=m){
            m-=arr[i];
            cnt++;
        }
    }
    printf("%d\n",cnt);

    return 0;
}