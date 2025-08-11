#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_able(int jump, int c, vector<int> &point){
    int last = point[0];
    int cnt = 1;
    for(int i = 1; i < point.size(); i++){
        if(point[i]-last < jump) continue;
        cnt++;
        last = point[i];
    }
    return c <= cnt;
}

int main(){

    int N, C;
    cin >> N >> C;

    vector <int> point(N);
    for(int i = 0; i < N; i++) cin >> point[i];

    sort(point.begin(), point.end());

    int low = 1;
    int high = point[N-1] - point[0];
    int mid;

    while(low <= high){
        mid = (low + high) / 2;
        if(is_able(mid, C, point)){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    cout << high;

    return 0;
}