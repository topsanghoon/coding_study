#include <iostream>
#include <vector>

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
    int n, m;
    cin >> n >>  m;

    priority_map(m+2);

    for(int i = n; i <= m; i++){
        if(priority[i] == 1) cout << i << "\n";
    }
    
    return 0;
}