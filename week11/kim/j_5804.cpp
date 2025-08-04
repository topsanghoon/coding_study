#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int n,c;

bool canPlant(int dist){ // O(200000)
    int tmp = c-1;
    int cur = arr[0];
    for(int i=1;i<n;i++){

        if(arr[i]-cur >= dist){
            tmp--;
            cur = arr[i];
        }
    }
    return tmp <= 0;
}

int main(){

    
    int answer;
    cin >> n >> c;

    arr = vector<int>(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int s = 0;
    int e = arr[n-1];

    canPlant(3);

    int mid;
    int ans = 0;
    while(s<=e){
        mid = (s+e)/2;
        //cout << "mid: "<<mid;
        if(canPlant(mid)){
            //cout << "o" <<'\n';
            s = mid+1;
            ans = mid;
        } else {
            //cout << "x" <<'\n';
            e = mid-1;
        }
    }

    cout << ans;


    return 0;  
}