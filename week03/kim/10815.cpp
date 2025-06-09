#include <iostream>
#include <set>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n;
    int a;
    set<int> cardset;
    for(int i=0;i<n;i++){
        cin >> a;
        cardset.insert(a);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> a;
        cout << cardset.count(a)<<' ';
    }
    
    return 0;
}