#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;
    map<int, int> m1;
    int num=0;
    for(int i=0;i<N;i++){
       cin>>num;
       m1[num]++; 
    }
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>num;
        if(m1.find(num) != m1.end()){
            cout<<m1[num]<<' ';
        }else{
            cout<<0<<' ';
        }
        
    }
    
    return 0;
}
