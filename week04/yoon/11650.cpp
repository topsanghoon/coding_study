#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    vector <pair<int, int>> cor; //pair로 저장해서 sort
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        cor.push_back({x,y});
    }

    sort(cor.begin(), cor.end());

    for(int i = 0; i < n; i++){
        cout << cor[i].first << " " << cor[i].second << "\n";
    }

    return 0;
}