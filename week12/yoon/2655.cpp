#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int main(){

    int n;
    cin >> n;

    unordered_map<int, int> WeightToHeight;
    unordered_map<int, int> WeightToWidth;
    unordered_map<int, int> WeightToIdx;

    vector<int> Weights, Widths;

    for(int i =0; i < n; i++){
        int width, height, weight;
        cin >> width >> height >> weight;

        WeightToHeight[weight] = height;
        WeightToWidth[weight] = width;
        WeightToIdx[weight] = i + 1;

        Weights.push_back(weight);
        Widths.push_back(width);
    }

    Weights.push_back(0);
    Widths.push_back(0);

    sort(Weights.begin(), Weights.end());
    sort(Widths.begin(), Widths.end());

    vector<vector<int>> answer(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n; j++){
            if(WeightToWidth[Weights[i]] > Widths[j]) answer[i][j] = answer[i-1][j];
            else if(WeightToWidth[Weights[i]] == Widths[j]){
                answer[i][j] = answer[i-1][j] + WeightToHeight[Weights[i]];
            }
            else{
                answer[i][j] = max(answer[i-1][j], answer[i][j-1]);
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout << WeightToIdx[Weights[i]] << "   ";
    //     for(int j = 0; j <= n; j++){
    //         cout << answer[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int target;
    for(int i = n; i > 0; i--){
        if(answer[n][i] != answer[n][i-1]){
            target = i;
            break;
        }
    }

    int block_cnt = 0;
    stack<int> block_order;
    for(int i = n; i > 0; i--){

        if(answer[i][target] != answer[i-1][target]){
            block_cnt++;
            block_order.push(WeightToIdx[Weights[i]]);

        }

        for(int j = i - 1; j > 0; j--){
            bool is_break = false;
            if(answer[j][target] != answer[j-1][target]){
                for(int k = target; k > 0; k--){
                    if(answer[j][k] != answer[j][k-1]){
                        target = k;
                        is_break = true;
                        break;
                    }
                }
            }
            if(is_break)break;
        }
    }

    cout << block_cnt << "\n";
    while(!block_order.empty()){
        cout << block_order.top() << "\n";
        block_order.pop();
    }

    return 0;
}