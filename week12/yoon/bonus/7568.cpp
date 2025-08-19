#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<tuple<int, int, int>> HWI(n);
    for(int i = 0; i < n; i++){
        int weight, height;
        cin >> weight >> height;
        HWI[i] = {weight, height, i};
    }

    vector<int> answer (n);
    for(int i = 0; i < n; i++){
        int rank = 1;
        auto [weight, height, idx] = HWI[i];
        for(int j = 0; j < n; j++){
            if(i == j) continue;

            auto [target_weight, target_height, target_cur] = HWI[j];
            if(height >= target_height || weight >= target_weight) continue;
            
            rank++;
            
        }

        answer[idx] = rank;
    }




    for(int i = 0; i < n; i++) cout << answer[i] << " ";

    return 0;
}