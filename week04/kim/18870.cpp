#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    vector<int> tmp = arr;
    sort(tmp.begin(), tmp.end());
    
    int num = 0;
    unordered_map<int,int> arr_rank;
    arr_rank[tmp[0]] = num;
    
    for(int i=1;i<tmp.size();i++){
        if(tmp[i-1]<tmp[i]){
            num++;
        }
        arr_rank[tmp[i]] = num;
    }
    
    for(int i=0;i<arr.size();i++){
        cout << arr_rank[arr[i]] << " ";
    }
    
    return 0;
}