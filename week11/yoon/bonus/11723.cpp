#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<bool> S(20+1, false);
    while(n--){
        string request;
        cin >> request;

        if(request == "all"){
            fill(S.begin(), S.end(), true);
            continue;
        }
        if(request == "empty"){
            fill(S.begin(), S.end(), false);
            continue;
        }
        
        int num;
        cin >> num;
        if(request == "add"){
            S[num] = true;
        }
        else if(request == "remove"){
            S[num] = false;
        }
        else if(request == "check"){
            if(S[num]) cout << "1\n";
            else cout << "0\n";
        }
        else if(request == "toggle"){
            if(S[num]) S[num] = false;
            else S[num] = true;
        }
    }
    return 0;
}