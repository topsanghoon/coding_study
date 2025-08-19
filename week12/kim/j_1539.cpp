#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip> 

using namespace std;

#define INT_MAX 2147483647

struct Dol{
    
    int area;
    int height;
    int weight;
    
    int last;
    
    Dol(int area, int height, int weight, int last) : 
    area(area), height(height), weight(weight), last(last){}
    
    
    
};


vector<Dol> arr;
vector<vector<Dol>> dp;

bool findDol(int src_y, int src_x, int dst){

    if(src_y==1){
        //cout << src_x << '\n';
        return (src_x==dst);
    }
    int last = dp[src_y][src_x].last;
    bool ret = findDol(src_y-1, last, dst);

    if(ret == false){
        //cout << src_x << '\n';
        ret = (src_x==dst);
    }  

    

    return ret;
}

void printDol(int src_y, int src_x){

    if(src_y==1){
        cout << src_x << '\n';
        return ;
    }
    int last = dp[src_y][src_x].last;
    printDol(src_y-1, last);
    if(last!=src_x){
        cout << src_x << '\n';
    }
    
}

int getDolCount(int src_y, int src_x){
    
    if(src_y==1){
        return 1;
    }

    int last = dp[src_y][src_x].last;
    int sum = getDolCount(src_y-1, last);
    if(last!=src_x){
        sum++;
    }
    return sum;

}

int main()
{
    int n;
    cin >> n;

    arr = vector<Dol>(n+1,Dol(0,0,0,0));
    dp = vector<vector<Dol>>(n+1,vector<Dol>(n+1,Dol(0,0,0,0)));

    int answer_height = 0;
    int answer_cnt = 0;
    stack<int> answer_rd;
    
    int area,height,weight;
    for(int i=1;i<=n;i++){
        cin >> area >> height >> weight;
        arr[i].area = area;
        arr[i].height = height;
        arr[i].weight = weight;
    }
    


    for(int i=1;i<=n;i++){
        dp[1][i].area = arr[i].area;
        dp[1][i].height = arr[i].height;
    }

    for(int i=2;i<=n;i++){

       for(int j=1;j<=n;j++){
            int mx_height = -1;
            int mx_idx = 0;
            for(int k=1;k<=n;k++){
                
                if(arr[j].area < arr[k].area) continue;
                if(arr[j].weight < arr[k].weight) continue;
                if(findDol(i,j,k)) continue;                

                if(mx_height < dp[i-1][k].height){
                    mx_idx = k;
                    mx_height = dp[i-1][k].height;
                }
            }
            
            
            if(mx_height!=-1 && (dp[i-1][j].height < dp[i-1][mx_idx].height + arr[j].height)){
                dp[i][j].area = arr[mx_idx].area;
                dp[i][j].height = dp[i-1][mx_idx].height + arr[j].height;
                dp[i][j].last = mx_idx;
            } else {
                dp[i][j].last = j;
                dp[i][j].height = dp[i-1][j].height;
            }
            
        }
    }



    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         if(dp[i][j].height == dp[i-1][j].height)
    //             cout << setw(5) << 0;  // 5칸 폭으로 0 출력
    //         else
    //             cout << setw(5) << dp[i][j].height; // 5칸 폭으로 값 출력
    //     }
    //     cout << '\n';
    // }

    int mx_height = 0;
    int mx_idx = 0;

    for(int i=1;i<=n;i++){
        if(mx_height < dp[n][i].height){
            mx_height = dp[n][i].height;
            mx_idx = i;
        }
    }

    cout <<getDolCount(n,mx_idx) << '\n';
    printDol(n,mx_idx);

    return 0;
}