#include <stdio.h>

void print_star(int n, int i, int j){
    
    if((((j-1)/n)%3==1 &&((i-1)/n)%3==1)){
            printf(" ");
    } else {
        if(n==1){
            printf("*");
            return;
        }
        print_star(n/3,i,j);
    }
}

int main(){

    int n;    
    scanf("%d ", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            print_star(n,i,j);
        }
        printf("\n");
    }

    return 0;
}