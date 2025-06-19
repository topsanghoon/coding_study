#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int,int>> arr = vector<pair<int,int>>(n);
    
    pair<int,int> p = make_pair(0,0);
    for(int i=0; i<n; i++){
        cin >> p.first >> p.second;
        arr[i] = p;
    }

    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        cout <<  arr[i].first << " " << arr[i].second<< '\n';
    }
    
    return 0;
}
