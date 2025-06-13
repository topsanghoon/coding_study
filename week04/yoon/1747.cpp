#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

#define end_v 1003002

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

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_map(end_v);

    for(int i = n; i <= end_v; i++){
        if(priority[i] == 1){
            string ori = to_string(i);
            string rev = ori;
            reverse(rev.begin(), rev.end());
            if(ori == rev) {
                cout << i;
                break;
            }
        }
    }

    return 0;
}