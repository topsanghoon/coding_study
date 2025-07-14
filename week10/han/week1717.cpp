#include <iostream>

using namespace std;

// 집합의 표현
// https://www.acmicpc.net/problem/1717
int Array[1000000 + 1] = {0, };

int find(int x) {
  if (Array[x] == x) return x;
  else return Array[x] = find(Array[x]);
}

void unionGroup(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (x < y) Array[y] = x;
  else Array[x] = y;
}

bool isUnion(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return true;
  else return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    Array[i] = i;
  }

  int command, a, b;
  for (int i = 0; i < m; i++) {
    cin >> command >> a >> b;
    if (command == 0) {
      unionGroup(a, b);
    } 
    else if (command == 1) {
      if (isUnion(a, b)) cout << "YES\n";
      else cout << "NO\n";
    }
  }
}