//20:32  20:58
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);      
    cin.tie(0);                         

    int n =0, m=0;
    cin >> n >> m;

    vector <long> sum_list;
    sum_list.push_back(0);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        long sum = temp + sum_list[i];
        sum_list.push_back(sum);
    }

    while(m--){
        int start = 0, end = 0;
        cin >> start >> end;

        long sum = sum_list[end] - sum_list[start - 1];
        cout << sum << "\n";
    }

    return 0;
}