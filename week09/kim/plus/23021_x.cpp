//등산로
//https://www.acmicpc.net/problem/23021


#include <iostream>
#include <vector>
using namespace std;

void run();

int main(){


    int tc;
    cin >>tc;

    for(int i=0;i<tc;i++){
        run();
    }

    return 0;
}

void run(){

    int m,n,x,c,d;
    cin >> m >> n >> x >> c >> d; 

    vector<int> e_mountains = vector<int>(m);
    vector<int> w_mountains = vector<int>(n);

    for(int i=0;i<m;i++){
        cin >> e_mountains[i];
    }
    for(int i=0;i<n;i++){
        cin >> w_mountains[i];
    }



}