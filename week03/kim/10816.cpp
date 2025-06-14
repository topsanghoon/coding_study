#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    unordered_map<int,int> cardMap;
    int a;
    while(n--){
        cin >> a;
        if(cardMap[a]==0){
            cardMap[a] = 1;
            continue;
        }
        cardMap[a]++;
    }

    int m;
    cin >> m;
    while(m--){
        cin >> a;
        cout<<cardMap[a]<<" ";
    }
    
}
