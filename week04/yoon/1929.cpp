#include <iostream>
#include <vector>

using namespace std;

vector <bool> priority;
void priority_map(int m){    //소수를 구하는 함수
    priority.resize(m, 1);

    priority[0] = false, priority[1] = false;
    for(int i = 2; i*i <m; i++){
        if(priority[i] == false) continue;
        for(int j = i * i; j < m; j += i){
              priority[j] = false;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >>  m;

    priority_map(m+2);

    for(int i = n; i <= m; i++){
        if(priority[i] == true) cout << i << "\n";
    }
    
    return 0;
}