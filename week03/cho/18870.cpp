#include <iostream>
using namespace std;
#include <set>
#include <vector>
int main() {
    int N;
    cin>>N;
    set<int> arr_s;
    vector<int> arr;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        arr_s.insert(tmp);
        arr.push_back(tmp);
    }
    
    // for(int x:arr)_s{
    //     cout<<x<<" ";
    // } // set에 넣으면 알아서 오름차순 정렬이 된다. 
    int idx=0;
    for (int i:arr) {
        for(int x:arr_s){
        if(i==x){
            cout<<idx<<" ";
            idx=0;
            break;
        }
        idx++;
    }
    }
    
    
    
    return 0;
}