#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647
#define MIN(X,Y) ((X<Y) ? (X) : (Y))

int main(){

    int n;
    scanf("%d ", &n);
    int* c = (int*)calloc(n+1,sizeof(int));
    for(int i=1;i<=n;i++){
        c[i] = INT_MAX;
    }

    c[n] = 0;
    for(int i=n;i>=1;i--){
        c[i-1] = MIN(c[i-1],c[i]+1);
        if(i%2==0){
            c[i/2] = MIN(c[i/2],c[i]+1);
        }
        if(i%3==0){
            c[i/3] = MIN(c[i/3],c[i]+1);
        }
    }

    printf("%d\n",c[1]);
    
}

