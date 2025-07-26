#include <iostream>
#include <queue>
#include <vector>
#include <cstring>//memset
using namespace std;

struct Pos {
	int x, y;
};

int N, M;
int Lab[50][50];
int visited[50][50];//bfs flood fill
bool check[50][50];//바이러스 놓았는지 확인
vector<Pos>Virus;
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
int Min = 987654321;

bool Spread() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Lab[i][j] != 1 && visited[i][j] == -1)
				return false;
		}
	}
	return true;
}

int bfs() {
	queue<Pos>q;
	int res = 0;
	memset(visited, -1, sizeof(visited));
	//바이러스가 있는 위치 모두 queue에 넣어주기
	for (int i = 0; i < Virus.size(); i++) {
		q.push({ Virus[i].x,Virus[i].y });
		visited[Virus[i].x][Virus[i].y] = 0;
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (Lab[nx][ny] != 1 && visited[nx][ny] == -1) {
				visited[nx][ny] = visited[x][y] + 1;
				res = visited[nx][ny];
				q.push({ nx,ny });
			}
		}
	}
	//마지막에 퍼뜨린 곳의 시간이 모든 빈 칸에 바이러스를 퍼뜨리는 최소 시간임
	return res;
}

//바이러스 위치 조합 구하기
void dfs(int x, int y, int cnt) {
	if (cnt == M) {
		int res = bfs();
		if (Spread() == true) {
			if (Min > res)
				Min = res;
		}
		return;
	}
	for (int i = x; i < N; i++) {
		for (int j = y; j < N; j++) {
			if (Lab[i][j] != 2 ||check[i][j] == true)
				continue;
			check[i][j] = true;
			Virus.push_back({ i,j });
			dfs(i, j, cnt + 1);
			check[i][j] = false;
			Virus.pop_back();
		}
		y = 0;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Lab[i][j];
		}
	}
	dfs(0, 0, 0);
	if (Min == 987654321)
		Min = -1;
	cout << Min << '\n';
	return 0;
}