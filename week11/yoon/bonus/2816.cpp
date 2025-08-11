#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> KBS(2);
    for(int i = 0; i < n; i++){
        string channel;
        cin >> channel;

        if(channel == "KBS1") KBS[0] = i;
        else if(channel == "KBS2") KBS[1] = i;
    }

    for(int i = 0; i < KBS[0]; i++) cout << "1";
    for(int i = 0; i < KBS[0]; i++) cout << "4";

    if(KBS[0] > KBS[1]) KBS[1]++;
    for(int i = 0; i < KBS[1]; i++) cout << "1";
    for(int i = 0; i < KBS[1] - 1; i++) cout << "4";

    return 0;
}