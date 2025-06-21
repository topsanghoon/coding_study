#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;
/*
void baek_1620_set(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int count = 0;
   int question = 0;
   cin >> count >> question;

   struct pockemon {
      string name;
      int num;
   };

   set<pockemon> pocketmon_tree;
   pockemon temp;
   string pocketmon_str;
   vector<string> pockemon_vector;
   for (int i = 0; i < count; i++) {
      cin >> pocketmon_str;
      temp.name = pocketmon_str;
      temp.num = i + 1;
      pocketmon_tree.insert(temp);
      pockemon_vector.push_back(pocketmon_str);
   }

   string question_str;
   for (int i = 0; i < question; i++) {
      cin >> question_str;

   }
}
*/
bool isNumber(const string& s) {
    try {
        stoi(s);
        return true;
    }
    catch (...) {
        return false;
    }
}

void baek_1620_map(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    int question = 0;
    cin >> count >> question;

    map<string, int> pocketmonMap;
    string pocketmon_str;
    vector<string> pockemon_vector;
    for (int i = 0; i < count; i++) {
        cin >> pocketmon_str;
        pocketmonMap[pocketmon_str] = i + 1;
        pockemon_vector.push_back(pocketmon_str);
    }

    string q_str;
    vector<string> answer;
    for (int i = 0; i < question; i++) {
        cin >> q_str;
        if (isNumber(q_str)) {
            answer.push_back(pockemon_vector[stoi(q_str) - 1]);
        }
        else {
            answer.push_back(to_string(pocketmonMap[q_str]));
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
}

void baek_1620_mapWithPair(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    int question = 0;
    cin >> count >> question;

    map<string, int> pocketmonMap;
    string pocketmon_str;
    vector<string> pockemon_vector;
    for (int i = 0; i < count; i++) {
        cin >> pocketmon_str;
        pocketmonMap.insert(make_pair(pocketmon_str, i + 1));
        pockemon_vector.push_back(pocketmon_str);
    }

    string q_str;
    vector<string> answer;
    for (int i = 0; i < question; i++) {
        cin >> q_str;
        if (isNumber(q_str)) {
            answer.push_back(pockemon_vector[stoi(q_str) - 1]);
        }
        else {
            answer.push_back(to_string(pocketmonMap[q_str]));
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
}

void baek_1620_unorderedMap(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    int question = 0;
    cin >> count >> question;

    unordered_map<string, int> pocketmonMap;
    string pocketmon_str;
    vector<string> pockemon_vector;
    for (int i = 0; i < count; i++) {
        cin >> pocketmon_str;
        pocketmonMap.insert(make_pair(pocketmon_str, i + 1));
        pockemon_vector.push_back(pocketmon_str);
    }

    string q_str;
    vector<string> answer;
    for (int i = 0; i < question; i++) {
        cin >> q_str;
        if (isNumber(q_str)) {
            answer.push_back(pockemon_vector[stoi(q_str) - 1]);
        }
        else {
            answer.push_back(to_string(pocketmonMap[q_str]));
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
}

void baek_10815(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    cin >> count;
    map<int, int> cards;
    int card = 0;
    for (int i = 0; i < count; i++) {
        cin >> card;
        cards.insert({ card, i });
    }
    int guessCount = 0;
    int guess = 0;
    vector<int> answer;
    cin >> guessCount;
    for (int i = 1; i <= guessCount; i++) {
        cin >> guess;
        /*if (cards[guess]) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }*/
        if (cards.find(guess) == cards.end()) {
            answer.push_back(0);
        }
        else {
            answer.push_back(1);
        }
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}

void baek_10815_unorderedMap(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    cin >> count;
    unordered_map<int, int> cards;
    int card = 0;
    for (int i = 0; i < count; i++) {
        cin >> card;
        cards.insert({ card, i });
    }
    int guessCount = 0;
    int guess = 0;
    vector<int> answer;
    cin >> guessCount;
    for (int i = 1; i <= guessCount; i++) {
        cin >> guess;
        /*if (cards[guess]) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }*/
        if (cards.find(guess) == cards.end()) {
            answer.push_back(0);
        }
        else {
            answer.push_back(1);
        }
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}

void jump(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int result = 0;
    vector<int> v;
    int n;
    cin >> n;
    int point;
    for (int i = 0; i < n; i++) {
        cin >> point;
        v.push_back(point);
    }
    sort(v.begin(), v.end());

    int fir_dis;
    for (int st = 0; st < n - 2; st++)
        for (int mid = st + 1; mid < n - 1; mid++) {
            fir_dis = v[mid] - v[st];
            auto lower_it = lower_bound(v.begin(), v.end(), fir_dis + v[mid]);
            auto upper_it = upper_bound(v.begin(), v.end(), 2 * fir_dis + v[mid]);
            result += upper_it - lower_it;

        }
    cout << result;
}

void baek_10816(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cardsCount = 0;
	cin >> cardsCount;
	unordered_map<string, int> cards;
	string tempCard;
	for (int i = 0; i < cardsCount; i++) {
		cin >> tempCard;
		auto result = cards.emplace(make_pair(tempCard, 1));
		if (result.second == false) {
			result.first->second += 1;
		}
	}

	int qCount = 0;
	cin >> qCount;
	vector<int> answer;
	string qCards;
	for (int i = 0; i < qCount; i++) {
		cin >> qCards;
		auto it = cards.find(qCards);
		if (it != cards.end()) {
			int input = it->second;
			answer.push_back(input);
		}
		else {
			answer.push_back(0);
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}

void baek_14425(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count = 0;
	int allCount = 0;
	cin >> count >> allCount;

	unordered_map<string, int> menu;
	string tempMenu;
	for (int i = 1; i <= count; i++) {
		cin >> tempMenu;
		//menu.emplace(make_pair(tempMenu,i));
		menu.insert({ tempMenu,i });
	}

	vector<string> question;
	string qtemp;
	int answer = 0;
	for (int i = 0; i < allCount; i++) {
		cin >> qtemp;
		//if (menu[qtemp]) answer += 1;
		if (menu.find(qtemp) != menu.end()) answer += 1;
	}

	cout << answer;
}

void baek_1374(void) {
	struct lesson {
		int num;
		int start;
		int end;
	};
	ios::sync_with_stdio(0);
	cin.tie(0);
	int count = 0;
	cin >> count;
	deque<lesson> input_lesson;
	int tmp_num;
	int tmp_start;
	int tmp_end;
	lesson temp;
	for (int i = 0; i < count; i++) {
		cin >> temp.num >> temp.start >> temp.end;
		input_lesson.push_back(temp);
	}

	sort(input_lesson.begin(), input_lesson.end(), [](const lesson& a, const lesson& b) {
		return a.start < b.start;
		});

	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 0; i < count; i++) {
		if (!minHeap.empty() && minHeap.top() <= input_lesson[i].start) {
			minHeap.pop();
		}
		minHeap.push(input_lesson[i].end);
	}
	cout << minHeap.size();
}

void baek_12891(void) {
	int count = 0;
	int part = 0;
	string str;
	int inputA = 0;
	int inputC = 0;
	int inputG = 0;
	int inputT = 0;

	cin >> count >> part;
	cin >> str;
	cin >> inputA >> inputC >> inputG >> inputT;

	int answer = 0;
	int Anum = 0;
	int Cnum = 0;
	int Gnum = 0;
	int Tnum = 0;

	queue<char> check;

	for (int i = 0; i < part; i++) {
		if (str[i] == 'A') Anum += 1;
		else if (str[i] == 'G') Gnum += 1;
		else if (str[i] == 'C') Cnum += 1;
		else if (str[i] == 'T') Tnum += 1;
	}
	if (Anum >= inputA && Gnum >= inputG && Cnum >= inputC && Tnum >= inputT) answer += 1;

	for (int i = part; i < count; i++) {
		if (str[i - part] == 'A') Anum -= 1;
		else if (str[i - part] == 'G') Gnum -= 1;
		else if (str[i - part] == 'C') Cnum -= 1;
		else if (str[i - part] == 'T') Tnum -= 1;

		if (str[i] == 'A') Anum += 1;
		else if (str[i] == 'G') Gnum += 1;
		else if (str[i] == 'C') Cnum += 1;
		else if (str[i] == 'T') Tnum += 1;

		if (Anum >= inputA && Gnum >= inputG && Cnum >= inputC && Tnum >= inputT) answer += 1;
	}
	cout << answer;
}

int main(void) {
    
    baek_10815_unorderedMap();
    return 0;
}