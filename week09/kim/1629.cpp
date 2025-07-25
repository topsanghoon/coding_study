#include <iostream>

using namespace std;

long long c;

long long getMul(long long a, long long b){

    long long mul = 1;

    if(b==0) return mul;

    long long to = getMul(a,b/2)%c;
    
    mul = (mul*to)%c;
    mul = (mul*to)%c;
    
    if(b%2==1){
        mul = (mul*a)%c;
    }

    return mul;
    
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a,b;
    cin>>a>>b>>c;

    cout<<getMul(a,b)<<'\n';
    
    return 0;
}