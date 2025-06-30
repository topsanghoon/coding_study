#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// https://www.acmicpc.net/problem/11729
// 하노이 탑 이동 순서
int answer = 0;
void recursiveHanoi(vector<pair<int,int>> &tarray, int n, int from, int destination, int through){
    if(n == 0) return;
    recursiveHanoi(tarray, n-1,from,through,destination);
    // answer++;
    // cout << from << " " << destination << "\n";
    tarray.push_back(make_pair(from,destination));
    recursiveHanoi(tarray, n-1,through,destination,from);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count;
    cin >> count;
    vector<pair<int,int>> array;
    recursiveHanoi(array,count, 1,3,2);
    cout << array.size() << "\n";
    for(int i = 0; i < array.size();i++){
        cout << array[i].first << " " << array[i].second << "\n";
    }
    return 0;
}