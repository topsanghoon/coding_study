#include <iostream>
#include <string>

using namespace std;

int main() {
    int n = 0;
    string temp;
    cin >> n >> temp;

    int result = 0;
    for(int i = 0; i < n; i++){
        result += temp[i] - '0';
    }

    cout << result;
    return 0;
}