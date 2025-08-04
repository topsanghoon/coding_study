#include <iostream>
#include <vector>

using namespace std;

int main(){

    long long n;
    cin >> n;

    long long ref = 1;
    int layer = 1;

    if(n == 1){
        cout << 1;
        return 0;
    }
    while(1){
        ref = ref + 6 * layer;
        layer++;    
        if(ref >= n) break;
    }
    
    cout << layer;

    return 0;
}