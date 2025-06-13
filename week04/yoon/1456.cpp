#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector <int> priority;
void priority_map(int m){
    priority.resize(m, 1);

    priority[0] = 0, priority[1] = 0;
    for(int i = 2; i < m; i++){
        if(priority[i] == 0) continue;
        for(int j = 2 * i; j < m; j += i){
              priority[j] = 0;
        }
    }
}

int main(){
    long long a, b;
    cin >> a >>  b;

    int end = (int)sqrt(b) + 2;
    
    priority_map(end);

    int result = 0;
    for(long long i = 2; i < end; i++){
        if(priority[i] == 1){
            for(long long j = 2; 1; j++){
                if(pow(i, j) > b) break; 
                if(pow(i, j) >= a) result++;
            }
        }
    }

    cout << result;
    
    return 0;
}