#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 트리 순회
// https://www.acmicpc.net/problem/1991
vector<vector<int>> graph(26,vector<int>(3));

char changeNumToAlpahbet(int num){
    char temp = 'A';
    temp += num;
    return temp;
}

void frontGo(int destination){
    cout << changeNumToAlpahbet(destination);
    int left = graph[destination][1];
    int right = graph[destination][2];
    if(left == -1 && right == -1) return;
    else{
        if(left != -1){
            frontGo(left);
        }
        if(right != -1){
            frontGo(right);
        }
    }
}

void centerGo(int destination){
    int left = graph[destination][1];
    int right = graph[destination][2];
    if(left == -1 && right == -1) {
        cout << changeNumToAlpahbet(destination);
        return;
    }
    else{
        if(left != -1){
            centerGo(left);
        }
        cout << changeNumToAlpahbet(destination);
        if(right != -1){
            centerGo(right);
        }
    }
}

void backGo(int destination){
    int left = graph[destination][1];
    int right = graph[destination][2];
    if(left == -1 && right == -1) {
        cout << changeNumToAlpahbet(destination);
        return;
    }
    else{
        if(left != -1){
            backGo(left);
        }
        if(right != -1){
            backGo(right);
        }
        cout << changeNumToAlpahbet(destination);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            char temp;
            cin >> temp;
            if(temp == '.') graph[i][j] = -1;
            else graph[i][j] = temp - 'A';
        }
    }

    sort(graph.begin(), graph.begin() + N, [](const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    });
    
    frontGo(0);
    cout << "\n";
    centerGo(0);
    cout << "\n";
    backGo(0);
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < 3; j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
}