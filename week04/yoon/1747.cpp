#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

#define end_v 1003002  
							//디버깅을 통해 찾은 최대의 소수이며 팰린드롬 수는 1003001

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

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_map(end_v);

    for(int i = n; i < end_v; i++){
        if(priority[i] == true){
            string ori = to_string(i);    //문자열로 바꾸고
            string rev = ori;     
            reverse(rev.begin(), rev.end());  //문자열을 뒤집어서 비교
            if(ori == rev) {
                cout << i;
                break;
            }
        }
    }

    return 0;
}