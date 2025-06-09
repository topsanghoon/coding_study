#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;  //n이 도감수, m이 문제 수

    unordered_map <int, string> dic_key_int;
    unordered_map <string, int> dic_key_string;
    for(int i = 1; i <= n; i++){
        string temp;
        cin >> temp;
        
        dic_key_int[i] = temp;
        dic_key_string[temp] = i;
    }

    while(m--){
        string temp;
        cin >> temp;

        if('0' <= temp[0] && temp[0] <= '9'){//첫 글자만 숫자여도 키가 숫자임
            cout << dic_key_int[stoi(temp)] << "\n";
        }
        else{
            cout << dic_key_string[temp] << "\n";
        }
    }

    return 0;
}