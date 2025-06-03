//20:17 - 20:27
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector <int> points;
    for(int i =0; i<n; i++){
        int temp;
        cin >> temp;
        points.push_back(temp);
    }

    int max = *max_element(points.begin(), points.end());
    double sum = 0;
    for(int i =0; i<n; i++){
        sum += ((double(points[i]) / double(max)) * 100);
    }
    
    cout << sum / double(n);

    return 0;
}