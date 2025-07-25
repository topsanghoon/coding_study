//https://www.acmicpc.net/problem/1030
#include <iostream>
#include <math.h>
using namespace std;


bool find_black(long long row,long long col,int s,int n,int k){
    if(s==0) return false;

    long long black_size =pow(n,s-1);
    long long black_start=(n-k)/2 *black_size;
    long long black_end = black_start + k*black_size -1;
    if(black_start <=row && row<=black_end && black_start<=col &&col<=black_end){
        return true;
    }
    return find_black(row%black_size,col%black_size,s-1,n,k);
}

int main() {
    int s,n,k; 
    long long row_1,row_2,col_1,col_2;
    cin>>s>>n>>k>>row_1>>row_2>>col_1>>col_2;
    for(int i=row_1;i<=row_2;i++){
        for(int j=col_1;j<=col_2;j++){
            if(find_black(i,j,s,n,k)) cout<<1;
            else cout<<0;
        }
        cout<<'\n';
    }
    return 0;
}