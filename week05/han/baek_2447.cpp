#include <iostream>
#include <vector>
#include <queue>
#define maxSize 6561+2
using namespace std;

// https://www.acmicpc.net/problem/2447
// 별 찍기 - 10
char map[maxSize][maxSize] = { 0, };
void drawStar(int x, int y, int N) {
	if (N == 1) {
		map[x][y] = '*';
		//cout << x << " " << y << "\n";
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				for (int k = 0; k < N / 3; k++) {
					for (int l = 0; l < N / 3; l++) {
						//cout << N / 3 << "\n";
						map[x+i*N/3+k][y+j*N/3+l] = ' ';
						//cout << x+i * N / 3 + k << " " << y+j * N / 3 + l << "\n";
					}
				}
			}
			else {
				drawStar((x + i*N/3), (y + j*N/3), N / 3);
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	//memset(map, (int)' ', sizeof(char) * maxSize * maxSize);
	drawStar(1, 1, N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}