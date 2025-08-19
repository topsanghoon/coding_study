#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> floors (n, vector<bool> (m+2, false));
    for(vector<bool> &single_floor : floors){
        int number;
        cin >> number;
        while(number--){
            int target;
            cin >> target;
            single_floor[target] = true;
        }
    }

    

    return 0; 
}