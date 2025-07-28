#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef struct _NODE{
    struct _NODE* left;
    struct _NODE* right;
    int idx;
}NODE;

typedef NODE* PNode;

vector<PNode> head;//n개의 belt 
vector<PNode> tail;//head tail의 idx는 위치
vector<PNode> node_pointer; 

PNode Creat_Node(int id){ //하나 추가 (초기 설정)
    PNode p = (PNode)malloc(sizeof(NODE));
    p->idx = id;
    p->left = NULL;
    p->right = NULL;

    node_pointer[id] = p;
    return p;
}

void print_all() {
    cout << "======= Current Belt States =======" << endl;
    for (int i = 1; i < head.size(); i++) {
        cout << "Belt " << i << " (" << head[i]->idx << " items): ";
        PNode cur = head[i]->right;
        while (cur != tail[i]) {
            cout << cur->idx << " ";
            cur = cur->right;
        }
        cout << endl;
    }
    cout << "===================================" << endl;
}


void Insert_Node(int id, PNode TAIL){ //타겟 노드 앞에 하나 추가 (초기 설정)
    PNode node = Creat_Node(id);

    node->left = TAIL->left;
    node->right = TAIL;
    TAIL->left->right = node;
    TAIL->left = node;
}

void Remove_Node(PNode target){
    target->left->right = target->right;
    target->right->left = target->left;
    free(target);
}


void request_100(int n){
    for(int i = 1; i <= n; i++){
        int temp;
        cin >> temp;

        Insert_Node(i, tail[temp]);
        head[temp]->idx++;
    }
}

void request_200(int from, int to) {
    if (head[from]->right == tail[from]) {
        // 옮길 노드가 없다면 그대로
        cout << head[to]->idx << '\n';
        return;
    }

    // 기존 belt[from]의 시작과 끝
    PNode from_first = head[from]->right;
    PNode from_last = tail[from]->left;

    // 기존 belt[to]의 첫 노드
    PNode to_first = head[to]->right;

    // 연결 순서 중요!
    head[to]->right = from_first;
    from_first->left = head[to];

    from_last->right = to_first;
    to_first->left = from_last;

    // from은 비우기
    head[from]->right = tail[from];
    tail[from]->left = head[from];

    // idx 갱신
    head[to]->idx += head[from]->idx;
    head[from]->idx = 0;

    cout << head[to]->idx << '\n';
}



void request_300(int belt1, int belt2) {
    PNode node1 = NULL, node2 = NULL;

    // 1. belt1 맨 앞 노드 떼기
    if (head[belt1]->right != tail[belt1]) {
        node1 = head[belt1]->right;
        node1->left->right = node1->right;
        node1->right->left = node1->left;
        head[belt1]->idx--;
    }

    // 2. belt2 맨 앞 노드 떼기
    if (head[belt2]->right != tail[belt2]) {
        node2 = head[belt2]->right;
        node2->left->right = node2->right;
        node2->right->left = node2->left;
        head[belt2]->idx--;
    }

    // 3. belt1에 node2 삽입
    if (node2 != NULL) {
        node2->right = head[belt1]->right;
        node2->left = head[belt1];
        head[belt1]->right->left = node2;
        head[belt1]->right = node2;
        head[belt1]->idx++;
    }

    // 4. belt2에 node1 삽입
    if (node1 != NULL) {
        node1->right = head[belt2]->right;
        node1->left = head[belt2];
        head[belt2]->right->left = node1;
        head[belt2]->right = node1;
        head[belt2]->idx++;
    }

    cout << head[belt2]->idx << '\n';
}

void request_400(int from, int to) {
    int move_num = head[from]->idx / 2;
    if (move_num == 0) {
        cout << head[to]->idx << '\n';
        return;
    }

    // 잘라낼 구간: head[from]->right ~ cutoff_left
    PNode from_first = head[from]->right;
    PNode cutoff_left = head[from];
    for (int i = 0; i < move_num; ++i) {
        cutoff_left = cutoff_left->right;
    }
    PNode cutoff_right = cutoff_left->right;

    // belt[from] 앞 절반 제거
    head[from]->right = cutoff_right;
    cutoff_right->left = head[from];

    // belt[to]에 삽입 (맨 앞에 붙임)
    PNode to_first = head[to]->right;

    head[to]->right = from_first;
    from_first->left = head[to];

    cutoff_left->right = to_first;
    to_first->left = cutoff_left;

    // idx 갱신
    head[from]->idx -= move_num;
    head[to]->idx += move_num;

    cout << head[to]->idx << '\n';
}

void request_500(int target){
    int a = -1, b = -1;
    if(node_pointer[target]->left->left != NULL) a = node_pointer[target]->left->idx;
    if(node_pointer[target]->right->right != NULL) b = node_pointer[target]->right->idx;

    cout << (a + (2 * b)) << '\n';
}

void request_600(int target){
    int a = -1, b = -1, c = -1;
    if(head[target]->right != tail[target]) {
        a = head[target]->right->idx;
        b = tail[target]->left->idx;
    }
    c = head[target]->idx;

    cout << (a + 2 * b + 3 * c) << '\n';
}


int main() {
    int n;
    cin >> n;

    while(n--){
        int request_num;
        cin >> request_num;

        if(request_num == 100){
            int belt_num, node_num;
            cin >> belt_num >> node_num;
            
            head.resize(belt_num+1);
            tail.resize(belt_num+1);
            node_pointer.resize(node_num+1);

            for(int i = 1; i <= belt_num; i++){ //벨트 생성
                head[i] = (PNode)malloc(sizeof(NODE));
                tail[i] = (PNode)malloc(sizeof(NODE));

                head[i]->right = tail[i];
                head[i]->left = NULL;
                tail[i]->left = head[i];
                tail[i]->right = NULL;
                head[i]->idx = 0;
                tail[i]->idx = 0;
            }
            
            request_100(node_num);
        }else if(request_num == 200){
            int from, to;
            cin >> from >> to;
            request_200(from, to);

        }else if(request_num == 300){
            int belt1, belt2;
            cin >> belt1 >> belt2;
            request_300(belt1, belt2);

        }else if(request_num == 400){
            int from, to;
            cin >> from >> to;
            request_400(from, to);
        }else if(request_num == 500){
            int target;
            cin >> target;
            request_500(target);

        }else{
            int target;
            cin >> target;
            request_600(target);
        }
        print_all(); //프린트 함수
    }
    return 0;
}