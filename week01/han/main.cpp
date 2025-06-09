#include <iostream>
#include <vector>
using namespace std;
void baek_11720(void) {
	int count = 0;
	cin >> count;
	string num = "";
	cin >> num;

	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += num[i] - '0';
		//		cout << num[i] << endl;
	}
	cout << sum << endl;
}
void baek_1546(void) {
	int count = 0;
	cin >> count;
	int temp;
	vector<float> array;
	float max = 0;
	for (int i = 0; i < count; i++) {
		cin >> temp;
		array.push_back(temp);
		if (max < temp) {
			max = temp;
		}
	}
	float avg = 0;
	for (int i = 0; i < count; i++) {
		avg += array[i] / max * 100;
	}
	cout << avg / count;
}

void baek_11659(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int array_count = 0;
	int count = 0;
	cin >> array_count >> count;
	vector<int> array(array_count + 1);
	for (int i = 1; i < array_count + 1; i++) {
		cin >> array[i];
		array[i] = array[i] + array[i - 1];
	}
	int first, second;
	for (int i = 0; i < count; i++) {
		cin >> first >> second;
		cout << array[second] - array[first - 1] << '\n';
	}
}

void baek_11660(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int size, count;
	cin >> size >> count;
	//size = 4;
	//count = 3;
	vector<vector<int>> A(size + 1, vector<int>(size + 1, 0));
	/*A = {
		{0, 0, 0, 0, 0},
		{0, 1, 2, 3, 4},
		{0, 2, 3, 4, 5},
		{0, 3, 4, 5, 6},
		{0, 4, 5, 6, 7}
	};*/
	for (int i = 1; i <= size; ++i) {
		for (int j = 1; j <= size; ++j) {
			cin >> A[i][j];
		}
	}
	/*for (int i = 0; i <= size; ++i) {
		for (int j = 0; j <= size; ++j) {
			cout << A[i][j] << " ";
		}
		cout << '\n';
	}*/

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (j == 1) {
				A[i][j] += A[i - 1][j];
			}
			else if (i == 1) {
				A[i][j] += A[i][j - 1];
			}
			else {
				A[i][j] += A[i][j - 1] + A[i - 1][j] - A[i - 1][j - 1];
			}
		}
	}
	/*for (int i = 0; i <= size; ++i) {
		for (int j = 0; j <= size; ++j) {
			cout << A[i][j] << " ";
		}
		cout << '\n';
	}*/
	int first, second, third, fourth;
	for (int i = 0; i < count; i++) {
		cin >> first >> second >> third >> fourth;
		cout << A[third][fourth] - A[third][second - 1] - A[first - 1][fourth] + A[first - 1][second - 1] << '\n';
	}
}

void baek_10986(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int count, num;
	cin >> count >> num;
	vector<long long> array(count + 1, 0);
	vector<long long> sectionSumArray(count + 1, 0);
	vector<long long> etcArray(num, 0);
	for (int i = 1; i <= count; i++) {
		cin >> array[i];
		sectionSumArray[i] = sectionSumArray[i - 1] + array[i];
		etcArray[sectionSumArray[i] % num] += 1;
	}
	long long answer = 0;
	for (int i = 0; i < num; i++) {
		if (i == 0) {
			answer += etcArray[0];
		}
		answer += etcArray[i] * (etcArray[i] - 1) / 2;
	}
	cout << answer << '\n';
}

void baek_2563(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int count = 0;
	cin >> count;
	int paper[100][100] = { 0, };
	int x_pos = 0, y_pos = 0;
	for (int i = 0; i < count; i++) {
		cin >> x_pos >> y_pos;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				paper[y_pos + j][x_pos + k] = 1;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j]) {
				sum += 1;
			}
		}
	}
	cout << sum << "\n";
}

void baek_2567(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int count = 0;
	cin >> count;
	int paper[100][100] = { 0, };
	int x_pos = 0, y_pos = 0;
	for (int i = 0; i < count; i++) {
		cin >> x_pos >> y_pos;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				paper[y_pos + j][x_pos + k] = 1;
			}
		}
	}
	/*for (int j = 0; j < 100; j++) {
		for (int k = 0; k < 100; k++) {
			cout << paper[j][k];
		}
		cout << "\n";
	}*/
	int sum = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (i == 0 || i == 99 || j == 0 || j == 99) {
				if (paper[i][j] == 1) {
					sum += 1;
				}
			}
			else {
				if (paper[i][j] == 1) {
					if (paper[i - 1][j] == 0 || paper[i + 1][j] == 0 || paper[i][j - 1] == 0 || paper[i][j + 1] == 0) {
						sum += 1;
						if (paper[i - 1][j] == 0 && paper[i][j - 1] == 0) {
							sum += 1;
						}
						else if (paper[i - 1][j] == 0 && paper[i][j + 1] == 0) {
							sum += 1;
						}
						else if (paper[i + 1][j] == 0 && paper[i][j + 1] == 0) {
							sum += 1;
						}
						else if (paper[i + 1][j] == 0 && paper[i][j - 1] == 0) {
							sum += 1;
						}
					}

				}
			}
		}
	}
	cout << sum << "\n";
}

void baek_temp_2567(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int count = 0;
	cin >> count;
	int paper[102][102] = { 0, };
	int x_pos = 0, y_pos = 0;
	for (int i = 0; i < count; i++) {
		cin >> x_pos >> y_pos;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				paper[y_pos + 1 + j][x_pos + 1 + k] = 1;
			}
		}
	}
	/*for (int j = 0; j < 100; j++) {
		for (int k = 0; k < 100; k++) {
			cout << paper[j][k];
		}
		cout << "\n";
	}*/
	int sum = 0;
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			if (paper[i][j] == 1) {
				if (paper[i - 1][j] == 0 || paper[i + 1][j] == 0 || paper[i][j - 1] == 0 || paper[i][j + 1] == 0) {
					sum += 1;
					if (paper[i - 1][j] == 0 && paper[i][j - 1] == 0) {
						sum += 1;
					}
					else if (paper[i - 1][j] == 0 && paper[i][j + 1] == 0) {
						sum += 1;
					}
					else if (paper[i + 1][j] == 0 && paper[i][j + 1] == 0) {
						sum += 1;
					}
					else if (paper[i + 1][j] == 0 && paper[i][j - 1] == 0) {
						sum += 1;
					}
				}
			}

		}
	}
	cout << sum << "\n";
}

int main(void) {
	baek_temp_2567();
}