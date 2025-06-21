#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    unordered_set <string> strings;
    while(n--){
        string temp;
        cin >> temp;
        strings.insert(temp);
    }

    int cnt = 0;
    while(m--){
        string temp;
        cin >> temp;

        if(strings.find(temp) != strings.end()) cnt++;
    }
    cout << cnt;   
}