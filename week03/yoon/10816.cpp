#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){

    int n, m;
    cin >> n;

    unordered_map <int, int> map;
    while(n--){
        int temp = 0;
        cin >> temp;
        if(map[temp] >= 1){
            map[temp]++;
        }
        else map[temp] = 1;
    }

    cin >> m;
    while(m--){
        int temp = 0;
        cin >> temp;
        
        cout << map[temp] << " ";
    }

    return 0;
}