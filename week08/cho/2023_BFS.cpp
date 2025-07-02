#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int main() {

    int N;
    cin>>N;

    queue<int> dec;
    dec.push(2);
    dec.push(3);
    dec.push(5);
    dec.push(7);

    while(!dec.empty()){
        int num =dec.front();
        dec.pop();
        
        string tmp_str = to_string(num);
        if(tmp_str.length() ==N){
            cout<<num<<'\n';
            continue;
        }
        
        bool flag =false;
        for (int i=1; i<10; i+=2) {
            int tmp = num*10+i;
            for (int j=2; j<=sqrt(tmp); j++) {
                if(tmp %j ==0) {
                    flag = true;
                    break;                    
                }
            }
            if(flag==false) {
                 dec.push(tmp);
            }
            else{
                flag =false;
            }
        } 
        
        }
        
    
    
    
    

    
    return 0;
}