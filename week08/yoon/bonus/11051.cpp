#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, K;
    cin >> N >> K;
    int N_K = N - K;


    long long upper = 1;
    long long lower = 1;
    while(N_K != 0){
        upper *= N;
        if(upper % N_K == 0) {
            upper = (upper / N_K) % 10007;
        }
        else{
            lower *= (N_K);
        }

        N--;
        N_K--;
    }
    

    cout << ( upper / lower ) % 10007;
}