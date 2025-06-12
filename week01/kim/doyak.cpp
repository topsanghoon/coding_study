#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    int answer = 0;
    cin >> n;
    vector<int> a = vector<int>(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int jump = 0;
    for(int i=0;i<a.size()-2;i++){
        int first = a[i];
        for(int j=i+1;j<a.size()-1;j++){
            int second = a[j];
            for(int k=j+1;k<a.size();k++){
                if((a[j]-a[i])<=(a[k]-a[j]) && (a[k]-a[j]) <= (a[j]-a[i])*2){
                    answer++;
                }
            }
        }
    }
    cout<<answer<<'\n';
    return 0;
}



//https://jungol.co.kr/problem/2788
