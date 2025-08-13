//빌런 호석
//https://www.acmicpc.net/problem/22251
#include <iostream>
#include <vector>

using namespace std;
vector<int> arr;
vector<int> Narr;

int graph[10][7] = {
    {1,1,1,1,1,1,0},
    {0,1,1,0,0,0,0},
    {1,1,0,1,1,0,1},
    {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},
    {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},
    {1,1,1,0,0,0,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1},
};
int n,k,p,x;
int ans = 0;

int get_toggle(int src, int dst){  //O(7)
    int ret = 0;
    for(int i=0;i<7;i++){
        if(graph[src][i]==graph[dst][i]) continue;
        ret++;
    }
    return ret;
}

void dfs(int depth, int cur_num, int remain_p){

    if(depth==k) {
        if(1<=cur_num && cur_num<=n){
            ans++;
            //cout<<cur_num<<"\n";
        }
        return ;
    }

    for(int i=0;i<10;i++){
                
        int require = get_toggle(arr[depth],i);
        //cout << "cur_num: "<<cur_num <<", remained_p: "<<remain_p << '\n';
        if(remain_p < require) continue;
        dfs(depth+1, cur_num*10+i, remain_p-require);
    }

}

int main(){

    
    cin >> n >> k >> p >> x;
    arr = vector<int>(k);
    Narr = vector<int>(k);

    int idx = k-1;
    int tmp = x;

    while(tmp && idx>=0){
        arr[idx--] = tmp%10;
        tmp/=10;
    }

    idx = k-1;
    tmp = n;
    while(tmp && idx>=0){
        Narr[idx--] = tmp%10;
        tmp/=10;
    }

    // for(int i=0;i<Narr.size();i++){
    //     cout << Narr[i];
    // }
    dfs(0,0,p);
    // for(int i=0;i<=Narr[0];i++){
        
    // }


    cout << ans-1;


    return 0;
}

//88 2 5 10

// 8, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 36, 38, 39, 40, 42, 43, 45, 46, 47, 48, 49, 50, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80