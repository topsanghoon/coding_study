#include <iostream>
#include <vector>
using namespace std;

// 여행 가자
// https://www.acmicpc.net/problem/1976
int Array[200 + 1] = {0, };
int map[200 + 1][200 + 1] = {{0}};

int find(int x) {
  if (Array[x] == x)
    return x;
  else
    return Array[x] = find(Array[x]);
}

void unionGroup(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;

  if (x < y)
    Array[y] = x;
  else
    Array[x] = y;
}

bool isUnion(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return true;
  else
    return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  cin >> N;
  cin >> M;

  for(int i = 1; i < 201; i++){
    Array[i] = i;
  }
  
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> map[i][j];
      if(map[i][j] == 1){
        unionGroup(i, j);
      }
    }
  }

  vector<int> goal(M);
  for(int i = 0; i < M; i++){
    cin >> goal[i];
  }

  for(int i = 0; i < M; i++){
    for(int j = 0; j < M; j++){
      if(!isUnion(goal[i], goal[j])){
        cout << "NO";
        return 0;
      }
    }
  }

  cout << "YES";
  
}