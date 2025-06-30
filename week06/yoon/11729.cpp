#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> ans;
int cnt = 0;
void find_func(int cur, int from, int to, int left){
    cnt++;
    if( cur ==1 ){          //1개까지 도달하면 원하는 곳으로 움직이면 끝
        ans.push_back({from, to});
        return;
    }

    find_func(cur - 1, from, left, to); //7개라면 6개를 중간을 거치는 막대를 통해 옮긴후
    ans.push_back({from, to});          //가장 밑에걸 움직이고
    find_func(cur - 1, left, to, from); //중간 지점에 있는 6개를 목표 지점으로 이동

    return;
}

int main(){
    int n;
    cin >> n;
    
    find_func(n, 1, 3, 2);

    cout << cnt << "\n";
    for(pair<int, int> from_to : ans){
        cout << from_to.first << " " << from_to.second << "\n";
    }
    return 0;
}