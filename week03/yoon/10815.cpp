#include <iostream>
#include <unordered_set>


using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0, m = 0;
    cin >> n;
    unordered_set <int> deck;
    while(n--){
        int temp = 0;
        cin >> temp;
        deck.insert(temp);
    }

    cin >> m;
    while(m--){
        int temp = 0;
        cin >> temp;
        if(deck.find(temp) != deck.end()) cout << "1 ";
        else cout << "0 ";
    }

    return 0;
}