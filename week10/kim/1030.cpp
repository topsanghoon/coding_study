#include <iostream>
#include <vector>
using namespace std;

int s,n,k,r1,r2,c1,c2;
int fn;
void make_map(int n,int k, int i, int j, int s){


    int ps = (n-k)/2;
    int ped = (n+k)/2;

    if(ps<(j%n) && (j%n)<=ped && ps<(i%n) && (i%n)<=ped){
        cout << 1;
    } else {
        if(s>1){
            make_map(n/fn,k/fn,i,j,s-1);
        } else {
            cout << 0;
        }
    }
}

int main(){

    
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    fn = n;

    for(int i=0;i<s-1;i++){
        n*=fn;
        k*=fn;
    }
    for(int i=r1+1;i<=r2+1;i++){
        for(int j=c1+1;j<=c2+1;j++){
            make_map(n,k,i,j,s);
        }
        cout<<'\n';
    }

    return 0;
}