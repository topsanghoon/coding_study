#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    while(1){

        vector<int> line(3);
        cin >> line[0] >> line[1] >> line[2];
        
        sort(line.begin(), line.end());
        if(line[2] == 0) return 0;

        if(line[0] + line[1] <= line[2]){
            cout << "Invalid\n";
            continue;
        }
        else if(line[0] == line[1]){
            if(line[0] == line[2]) {
                cout << "Equilateral\n";
                continue;
            }
            cout << "Isosceles\n";
            continue;
        }
        else if(line[1] == line[2]){
            cout << "Isosceles\n";
            continue;
        }
        else{
            cout << "Scalene\n";
            continue;
        }
    }


    return 0;
}