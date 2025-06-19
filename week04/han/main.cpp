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

// 소수 구하기
bool isPrime(int num) {
	if (num == 1) return false;
	for (int i = 2; i <= (int)sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void baek_1929(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int lower, higher;

	cin >> lower >> higher;
	vector<int> answer;
	for (int i = lower; i <= higher; i++) {
		//if (isPrime(i)) answer.push_back(i);
		if (isPrime(i)) {
			cout << i << "\n";
		}
	}
}

// 거의 소수 구하기
void baek_1456(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long lower, higher;

	cin >> lower >> higher;

	int limit = (int)sqrt(higher);
	vector<bool> num_map(limit + 1, true);
	num_map[0] = false;
	num_map[1] = false;

	int answer = 0;

	for (int i = 2; i <= limit; i++) {
		if (num_map[i]) {
			for (int j = i * 2; j <= limit; j += i) {
				num_map[j] = false;
			}
		}
	}

	for (int i = 2; i <= limit; i++) {
		if (num_map[i]) {
			long long value = (long long)i * i;
			while (value <= higher) {
				if (value >= lower) {
					answer += 1;
				}
				if (value > higher / i) break;
				value *= i;
			}
		}
	}

	cout << answer;
}

// 소수 및 팰린드롬 수 구하기
void baek_1747(void) {
	
	vector<bool> array(2000000 + 1, 1);
	//vector<bool> array(10000 + 1, 1);
	array[0] = false;
	array[1] = false;
	for (long long i = 2; i < array.size(); i++) {
		if(array[i]){
			for (int j = 2*i; j < array.size(); j += i) {
				array[j] = false;
			}
		}
	}

	/*for (int i = 2; i * i <= array.size(); i++) {
		if (array[i]) {
			for (int k = i * i; k <= array.size(); k += i) {
				array[k] = false;
			}
		}
	}*/

	/*for (int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
		if (i % 1000 == 0) cout << "\n";
	}*/

	int lower;
	cin >> lower;
	int higher = 0;
	//cout << array.size() << "\n";
	for (int i = lower; i < array.size(); i++) {
		if (array[i] == true) {
			string temp = to_string(i);
			int tempSize = temp.size();
			bool check = true;	
			for (int j = 0; j < tempSize/2; j++) {
				if (temp[j] != temp[tempSize - j-1]) {
					check = false;
					break;
				}
			}
			
			if (check == true) {
				higher = i;
				break;
			}
		}
	}
	cout << higher;
}

// 좌표 정렬하기
void baek_11650(void) {
	int count;
	cin >> count;
	vector<pair<int, int> > array;

	int first, second;
	for (int i = 0; i < count; i++) {
		cin >> first >> second;
		array.push_back(make_pair(first, second));
	}

	sort(array.begin(), array.end());
	for (int i = 0; i < count; i++) {
		cout << array[i].first << " " << array[i].second << "\n";
	}
}

// 좌표 압축하기
void baek_18870(void) {
	int count = 0;
	cin >> count;
	vector<int> array;
	set<int> setArray;
	for (int i = 0; i < count; i++) {
		int temp;
		cin >> temp;
		array.push_back(temp);
		setArray.insert(temp);
	}

	unordered_map<int, int> pointMap;
	int index = 1;
	for (set<int>::iterator iter = setArray.begin(); iter != setArray.end(); iter++) {
		pointMap.insert(make_pair(*iter, index));
		index += 1;
	}

	vector<int> answer;
	for (int i = 1; i <= count; i++) {
		answer.push_back(pointMap[array[i - 1]]);
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] - 1 << " ";
	}
}

// 해밀턴 순환회로
int visited_1681[14] = { 0, };
int gmin = 13001;
int length;
int gDepth;
vector<int> answer;

void dfs_1681(const vector<vector<int>>& tArray, int target, int cValue, int depth) {
	if (depth == gDepth) {
		if (tArray[target][1] != 0) {
			int temp = cValue;
			temp += tArray[target][1];
			if (temp < gmin) gmin = temp;
		}
		return;
	}
	if (cValue > gmin) return;
	for (int i = 2; i <= gDepth; i++) {
		if (visited_1681[i]) continue;
		if (tArray[target][i] == 0) continue;
		if (i == target) continue;
		if (visited_1681[i] == 0) { 
			visited_1681[i] = 1; 
			dfs_1681(tArray, i, cValue + tArray[target][i], depth + 1);
			visited_1681[i] = 0;
		}
	}
}

void jungol_1681(void) {
	cin >> length;
	gDepth = length;

	vector<vector<int>> array(length+1, vector<int>(length+1, 0));
	for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= length; j++) {
			cin >> array[i][j];
		}
	}
	visited_1681[1] = 1;
	dfs_1681(array, 1, 0, 1);
	cout << gmin;

}