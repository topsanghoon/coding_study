//https://www.acmicpc.net/problem/1043
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
vector<int> depth;

int find_parent(int num){
    if(arr[num]==num) return num;
    else return arr[num]=find_parent(arr[num]);
}

void union_sets(int num1,int num2){
    num1 = find_parent(num1);
    num2 = find_parent(num2);
    if(num1 != num2){
        if(depth[num1] < depth[num2]) swap(num1,num2);
        arr[num2]=num1;
        if(depth[num1]==depth[num2]) depth[num1]++;
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    arr.resize(N+1);
    depth.resize(N+1, 0);
    
    for(int i=0; i<=N; i++) arr[i] = i;

    int truth_cnt;
    cin >> truth_cnt;
    vector<int> truth(truth_cnt);
    for(int i=0; i<truth_cnt; i++) {
        cin >> truth[i];
        union_sets(0, truth[i]);
    }

    vector<vector<int>> parties(M);
    for(int i=0; i<M; i++) {
        int cnt;
        cin >> cnt;
        parties[i].resize(cnt);
        for(int j=0; j<cnt; j++) {
            cin >> parties[i][j];
        }        
        for(int j=1; j<cnt; j++) {
            union_sets(parties[i][0], parties[i][j]);
        }
    }
    int res=0;
    for(int i=0;i<M;i++){
        bool x=true;
        for(int ser:parties[i])
        {
            if(find_parent(ser) == find_parent(0)){
                x=false;
                break;
            }
        }
        if(x) res++;
    }
    cout<<res<<'\n';
    return 0;
}
