#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<tuple<int, int, int, int>> flowers;
    for(int i = 0; i < n; i++) {
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;

        flowers.push_back({m1, d1, m2, d2});
    }

    sort(flowers.begin(), flowers.end());
    vector<string> flowers_bloom, flowers_dead;
    for(auto [m1, d1, m2, d2] : flowers){

        string day_1, day_2;
        if(m1 > 9) day_1 = to_string(m1);
        else day_1 = "0" + to_string(m1);

        if(d1 > 9) day_1 = day_1 + to_string(d1);
        else day_1 = day_1 + "0" + to_string(d1);
        
        if(m2 > 9) day_2 = to_string(m2);
        else day_2 = "0" + to_string(m2);

        if(d2 > 9) day_2 =  day_2 + to_string(d2);
        else day_2 = day_2 + "0" + to_string(d2);

        flowers_bloom.push_back(day_1);
        flowers_dead.push_back(day_2);
    }

    // for(int i = 0; i < n; i++){
    //     cout << flowers_bloom[i] << "   " << flowers_dead[i] << endl;
    // }

    bool is_able = true;
    int answer = 0;

    string ref_line = "0301", end_line = "1130";
    int start_idx = 0;
    while(ref_line <= end_line){
        int end_idx = upper_bound(flowers_bloom.begin() + start_idx, flowers_bloom.end(), ref_line) - flowers_bloom.begin() - 1;
        if(start_idx > end_idx) {
            is_able = false;
            break;
        }
        // cout << "ref_line : " << ref_line << "   start_idx : " << start_idx << "    end_idx : " << end_idx << endl;
        answer++;

        vector<string> temp;
        temp.assign(flowers_dead.begin() + start_idx, flowers_dead.begin() + end_idx + 1);
        sort(temp.begin(), temp.end());

        // for(int i = 0; i < temp.size(); i++) cout << temp[i];
        // cout << endl;

        ref_line = temp[temp.size()-1];
        start_idx = end_idx + 1;
        // cout << "changed ref_line : " << ref_line << endl;

    }

    if(is_able) cout << answer;
    else cout << 0;



    return 0;
}