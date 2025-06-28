#include <iostream>
using namespace std;

void move(int N,int start,int end){
    //cout<<N<<"번 start: "<<start<<" end: "<<end<<'\n';
    cout<<start<<" "<<end<<'\n';
}

void hanoi(int N, int start , int end , int sub){
    if(N==1){
        move(1,start,end);
    }else{
        hanoi(N-1,start,sub,end);
        move(N,start,end);
        hanoi(N-1,sub,end,start);
    }
}

int main() {
    int N;
    cin>>N;
    int count = (1<<N) -1;
    cout<<count<<'\n';
    hanoi(N,1,3,2);
    return 0;
}