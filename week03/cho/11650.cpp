#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main() {
    int N;
    cin>>N;
    int x,y;
    vector<pair<int, int>> arr;

    for(int i=0;i<N;i++){
        cin>>x>>y;
        arr.push_back({x,y});
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<N;i++){
        cout<<arr[i].first<<' '<<arr[i].second<<'\n';
    }
    
    
    return 0;
}
