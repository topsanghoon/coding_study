#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

// 단지번호 붙이기
int dfs(vector<vector<int>> &array, int loc_x, int loc_y) {
	if (array[loc_x][loc_y] == 0) return 0;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int count = 1;
	array[loc_x][loc_y] = 0;
	for (int i = 0; i < 4; i++) {
			int after_x = loc_x + dx[i];
			int after_y = loc_y + dy[i];
			count += dfs(array, after_x, after_y);
	}
	return count;
}
void jungol_1695(void) {
	int length;
	cin >> length;
	vector<vector<int>> array(length+2, vector<int>(length+2, 0));
	for (int i = 1; i <= length; i++) {
		string line;
		cin >> line;
		for (int j = 1; j <= length; j++) {
			array[i][j] = line[j-1] - '0';
		}
	}
	vector<int> answer;
	for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= length; j++) {
			if (array[i][j]) {
				int max = 0;
				max = dfs(array, i, j);
				if (max != 0) answer.push_back(max);
			}
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}