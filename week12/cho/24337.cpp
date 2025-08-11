#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N,a,b;
    cin>>N>>a>>b;
    int max_num = max(a,b);
    deque<int> arr;

    for(int i=a-1;i>0;i--){
        //cout<<"i: "<<i<<'\n';
        arr.push_front(i);
    }
    arr.push_back(max_num);
    //cout<<"max_num: "<<max_num<<'\n';
    for(int i=b-1;i>0;i--){
        //cout<<"i: "<<i<<'\n';
        arr.push_back(i);
    }


    int res_arr_size = arr.size();
    if(res_arr_size > N){
        cout<<-1;
        return 0;
    }
    else if(res_arr_size == N){
        for(int i:arr) cout<<i<<" ";
    }
    else{
        if(a==1){
            arr.insert(arr.begin()+a,N-res_arr_size,1);
        }
        else{
            arr.insert(arr.begin(),N-res_arr_size,1);
        }
        for(int i:arr) cout<<i<<" ";
    }
    
    return 0;
}