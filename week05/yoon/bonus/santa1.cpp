#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int Q, N, M;
struct BOX {
    int idx, belt, weight;
    BOX *prev, *next;
} box[100005];
unordered_map<int, BOX *> box_map;  // id -> BOX 값
int idx[100005], weights[100005];
struct BELT {
    BOX *front, *end;
    bool broken;
} belt[15];// belt[i] := i 번 벨트에서 가장 앞에 있는 박스 번호, 없다면 0
void push_box(int belt_idx, BOX *box) {
    box_map[box->idx] = box;
    box->belt = belt_idx;
    if (belt[belt_idx].front == NULL) {  // 만약 비어있는 벨트 였다면?
        box->prev = box->next = NULL;
        belt[belt_idx].front = belt[belt_idx].end = box;
    }
    else {
        box->prev = belt[belt_idx].end, box->next = NULL;
        belt[belt_idx].end->next = box;
        belt[belt_idx].end = box;
    }
}


void input() {
    cin >> Q;
    int x;
    cin >> x >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> idx[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> weights[i];
    }
    int T = N / M;
    for (int i = 1; i <= M; i++) {
        for (int j = (i - 1) * T + 1; j <= i * T; j++) {
            box[j].idx = idx[j];
            box[j].belt = i;
            box[j].weight = weights[j];
            push_box(i, &box[j]);
        }
    }
}


BOX *drop_box(int i) {
    BOX *box = belt[i].front;
    box->belt = 0;
    box_map.erase(box->idx);
    belt[i].front = box->next;
    box->next = NULL;
    if (belt[i].front != NULL)
        belt[i].front->prev = NULL;
    return box;
}


long long int query_200(int W) {
    long long int sum = 0;  // 하차되는 상자들의 무게 총 합
    for (int i = 1; i <= M; i++) {
        if (belt[i].front == NULL) {  // 비어있는 벨트면 무시하기
            continue;
        }
        if (belt[i].broken) {  // 고장난 벨트도 무시하기
            continue;
        }
        if (belt[i].front->weight <= W) {
            sum += belt[i].front->weight;
            // 하차하기
            drop_box(i);
        }
        else {
            // 하차 했다가
            BOX *box = drop_box(i);
            // 다시 실기
            push_box(i, box);
        }
    }
    return sum;
}


int query_300(int id) {
    if (box_map.find(id) == box_map.end()) {  // 없는 상자인 경우
        return -1;
    }
    BOX *box = box_map[id];
    BOX *prev = box->prev, *next = box->next;
    int b = box->belt;
    if (prev == NULL && next == NULL) {  // 벨트 하나가 통째로 비어버리는 상황
        belt[b].front = belt[b].end = NULL;
    }
    else if (prev == NULL) {  // 벨트의 가장 앞 상자가 바뀌는 상황
        next->prev = NULL;
        belt[b].front = next;
    }
    else if (next == NULL) {  // 벨트의 가장 뒤 상자가 바뀌는 상황
        prev->next = NULL;
        belt[b].end = prev;
    }
    else {
        prev->next = next;
        next->prev = prev;
    }
    box_map.erase(id);
    return id;
}


int query_400(int id) {
    if (box_map.find(id) == box_map.end()) {  // 없는 상자인 경우
        return -1;
    }
    BOX *box = box_map[id];
    BOX *prev = box->prev, *next = box->next;
    int b = box->belt;
    BOX *front = belt[b].front, *end = belt[b].end;
    if (prev == NULL && next == NULL) {  // 벨트 하나가 통째로 비어버리는 상황
        // DO NOTHING
    }
    else if (prev == NULL) {  // 벨트의 가장 앞 상자가 바뀌는 상황
     // DO NOTHING
    }
    else if (next == NULL) {  // 벨트의 가장 뒤 상자가 바뀌는 상황
        prev->next = NULL;
        front->prev = box;
        box->next = front;
        box->prev = NULL;
        belt[b].front = box;
        belt[b].end = prev;
    }
    else {
        box->prev = NULL;
        prev->next = NULL;
        end->next = front;
        front->prev = end;
        belt[b].front = box;
        belt[b].end = prev;
    }
    return box_map[id]->belt;
}


int query_500(int b) {
    if (belt[b].broken) {
        return -1;
    }
    if (belt[b].front == NULL) {  // 즉, 삭제한 벨트가 이미 비어있는 친구면, 아무 일도 안해도 됨!
        belt[b].broken = true;
        return b;
    }
    int tgt = b;
    belt[b].broken = true;
    while (belt[tgt].broken) {
        tgt++;
        if (tgt > M)
            tgt = 1;
    }
    // 1. belt[b].front 와 belt[tgt].end 사이에 link 생성
    belt[b].front->prev = belt[tgt].end;
    belt[tgt].end->next = belt[b].front;
    // 2. belt[b] 의 상자들의 belt 값을 tgt로 변경
    for (BOX *it = belt[b].front; it; it = it->next) {
        it->belt = tgt;
    }
    // 3. belt[tgt]의 end 를 belt[b].end 로 변경
    belt[tgt].end = belt[b].end;
    return b;
}


vector<int> ans;
vector<pair<int, int>> Qs;
void pro() {
    for (int rep = 2; rep <= Q; rep++) {
        int q, v;
        cin >> q >> v;
        Qs.push_back({ q, v });
    }
    for (auto &p : Qs) {
        int query = p.first;
        if (query == 200) {
            int W = p.second;
            cout << query_200(W) << '\n';
        }
        else if (query == 300) {
            int id = p.second;
            cout << query_300(id) << '\n';
        }
        else if (query == 400) {
            int id = p.second;
            cout << query_400(id) << '\n';
        }
        else if (query == 500) {
            int b_num = p.second;
            cout << query_500(b_num) << '\n';
        }
    }
    for (int x : ans) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    pro();
    return 0;
}