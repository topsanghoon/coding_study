#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    vector <pair <int, int>> list;
    for(int i = 0; i < n; i++){
        int temp = 0;
        cin >> temp;

        list.push_back({temp, i});
    }

    sort(list.begin(), list.end());

    vector <int> result(n);
    int current = -1;
    int toggle = 1.1e9;
    for(int i = 0; i< n; i ++){
        
        if(toggle != list[i].first) current++;
        result[list[i].second] = current;
        toggle = list[i].first;
    }

    for(int i = 0; i < n; i++) cout << result[i] << " ";

    return 0;
}