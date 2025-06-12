#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <set>

using namespace std;

void baek_1874(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    cin >> count;

    vector<int> stack;
    int target;
    vector<int> target_collection;
    vector<char> answer;
    for (int i = 0; i < count; i++) {
        cin >> target;
        target_collection.push_back(target);
    }
    int start = 1;
    for (int i = 0; i < count; i++) {
        while (start <= target_collection[i]) {
            stack.push_back(start);
            answer.push_back('+');
            start += 1;
        }
        if (stack.back() == target_collection[i]) {
            stack.pop_back();
            answer.push_back('-');
        }
        else {
            cout << "NO";
            return;
        }
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
}

void baek_17298(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    cin >> count;
    vector<int> input;
    for (int i = 0; i < count; i++) {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }
    vector<int> stack;
    vector<int> answer(count, -1);
    for (int i = 0; i < count; i++) {
        while (stack.size() > 0 && input[stack.back()] < input[i]) {
            answer[stack.back()] = input[i];
            stack.pop_back();
        }
        stack.push_back(i);
    }
    for (int i = 0; i < count; i++) {
        cout << answer[i] << " ";
    }
}

void baek_2164(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    cin >> count;
    // vector<int> cards;
    // for (int i = 1; i <= count; i++) {
    //   cards.push_back(i);
    // }
    // while (cards.size() > 1) {
    //   cards.erase(cards.begin());
    //   int temp = cards[0];
    //   cards.erase(cards.begin());
    //   cards.push_back(temp);
    // }
    // cout << cards[0];
    queue<int> cards;
    for (int i = 1; i <= count; i++) {
        cards.push(i);
    }
    while (cards.size() > 1) {
        cards.pop();
        int temp = cards.front();
        cards.pop();
        cards.push(temp);
    }
    cout << cards.front();
}


void baek_11286(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int> maxHeap; // 음수 삽입
    priority_queue<int, vector<int>, greater<int>> minHeap; // 양수 삽입

    int count = 0;
    cin >> count;
    int input = 0;
    vector<int> answer;
    int temp_m = 0;
    int temp_p = 0;
    for (int i = 0; i < count; i++) {
        cin >> input;
        if (input < 0) {
            maxHeap.push(input);
        }
        else if (input == 0) {
            if (maxHeap.empty() && minHeap.empty()) {
                answer.push_back(0);
            }
            else if (maxHeap.empty()) {
                temp_p = minHeap.top();
                answer.push_back(temp_p);
                minHeap.pop();
            }
            else if (minHeap.empty()) {
                temp_m = maxHeap.top();
                answer.push_back(temp_m);
                maxHeap.pop();
            }
            else {
                temp_m = maxHeap.top();
                temp_p = minHeap.top();
                if (abs(temp_m) > abs(temp_p)) {
                    answer.push_back(temp_p);
                    minHeap.pop();
                }
                /*else if (abs(temp_m) < abs(temp_p)) {
                   answer.push_back(temp_m);
                   maxHeap.pop();
                }*/
                else {
                    answer.push_back(temp_m);
                    maxHeap.pop();
                }
            }
        }
        else {
            minHeap.push(input);
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}

// 회전초밥 (중)
void jungol_2572_temp(void) {
    int count = 0;
    int kindOf = 0;
    int serial = 0;
    int coupon = 0;

    cin >> count >> kindOf >> serial >> coupon;

    int foodmap[3001] = { 0, };

    vector<int> food;
    deque<int> check;

    int foodtemp = 0;
    int max = 0;
    for (int i = 0; i < count; i++) {
        cin >> foodtemp;
        food.push_back(foodtemp);
    }

    for (int i = 0; i < count; i++) {
        int isValid = 1;
        check.push_back(food[i]);
        foodmap[food[i]] += 1;
        // 체크
        for (int j = 0; j < check.size(); j++) {
            if (foodmap[check[j]] != 1) {
                isValid = 0;
                break;
            }
        }

        if (isValid == 1) {
            if (max < check.size()) {
                max = check.size();
            }
        }
        else {
            foodmap[check[0]] -= 1;
            check.pop_front();
        }
    }
    if (max > serial + 1) {
        cout << serial + 1;
    }
    else cout << max;
    //cout << max;

}

void jungol_2788(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    cin >> count;
    vector<int> array;
    int input;
    for (int i = 0; i < count; i++) {
        cin >> input;
        array.push_back(input);
    }
    sort(array.begin(), array.end());
    int answer = 0;
    for (int i = 0; i < count - 2; i++) {
        for (int j = i + 1; j < count - 1; j++) {
            for (int k = i + 2; k < count; k++) {
                if (((array[j] - array[i]) <= (array[k] - array[j])) && ((array[k] - array[j]) <= 2 * (array[j] - array[i]))) {
                    answer += 1;
                }
            }
        }
    }
    cout << answer << "\n";
}

void jungol_2788_binSearch(void) {
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

void jungol_2572(void) {
    int count = 0;
    int kindOf = 0;
    int serial = 0;
    int coupon = 0;

    cin >> count >> kindOf >> serial >> coupon;

    int foodmap[3001] = { 0, };

    vector<int> food;
    deque<int> check;

    int foodtemp = 0;
    int max = 0;
    int uniqueCount = 0;

    for (int i = 0; i < count; i++) {
        cin >> foodtemp;
        food.push_back(foodtemp);
    }

    for (int i = 0; i < count + serial; i++) {

        if (check.size() < serial) {
            check.push_back(food[i % count]);
            if (foodmap[food[i % count]] == 0) {
                uniqueCount += 1;
            }
            foodmap[food[i % count]] += 1;
        }
        else {
            if (foodmap[check.front()] == 1) {
                uniqueCount -= 1;
            }
            foodmap[check.front()] -= 1;
            check.pop_front();

            check.push_back(food[i % count]);
            foodmap[food[i % count]] += 1;
            if (foodmap[food[i % count]] == 1) {
                uniqueCount += 1;
            }
        }
        int uniqueTemp = uniqueCount;
        if (foodmap[coupon] == 0) uniqueTemp += 1;
        if (max < uniqueTemp) max = uniqueTemp;
    }
    cout << max;
}

int main(void) {
    jungol_2572();
}