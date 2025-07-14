#include <iostream>
#include <vector>
using namespace std;

// 거짓말
// https://www.acmicpc.net/problem/1043
int people[50+1] = {0, };

int find(int x) {
  if (people[x] == x)
    return x;
  else
    return people[x] = find(people[x]);
}

void unionGroup(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;

  if (x < y)
    people[y] = x;
  else
    people[x] = y;
}

bool isUnion(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return true;
  else
    return false;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    people[i] = i;
  }
  int knowCount;
  cin >> knowCount;
  for(int i = 0; i < knowCount; i++){
    int temp;
    cin >> temp;
    unionGroup(0, temp);
  }

  vector<vector<int>> party(50);
  for(int i = 0; i < M; i++){
    int temp;
    cin >> temp;
    for(int j = 0; j < temp; j++){
      int tempPerson;
      cin >> tempPerson;
      party[i].push_back(tempPerson);
    }
  }
  
  for(int i = 0; i < M; i++){
    for(int j = 0; j < party[i].size(); j++){
      for(int k = 0; k < party[i].size(); k++){
         unionGroup(party[i][0], party[i][j]);
       }
    }
  }

  int answer = 0;
  for(int i = 0; i < M; i++){
    bool canGo = true;
    for(int j = 0; j < party[i].size(); j++){
      if(find(party[i][j]) == 0){
        canGo = false;
        break;
      }
    }
    if(canGo) answer += 1;
  }
  cout << answer;
}