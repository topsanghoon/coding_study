//https://www.acmicpc.net/problem/1976
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

bool check_connect(int num1,int num2){
    num1 = find_parent(num1);
    num2 = find_parent(num2);
    return num1 == num2;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    arr.resize(N+1);
    depth.resize(N+1, 0);
    for(int i=1; i<=N; i++) arr[i] = i;

    int tmp=0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> tmp;
            if(tmp == 1) union_sets(i,j);
        }
    }

    vector<int> plan(M);
    for(int i=0; i<M; i++) cin >> plan[i];

    for(int i=1; i<M; i++) {
        if(!check_connect(plan[i-1], plan[i])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
