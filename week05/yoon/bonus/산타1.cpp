#include <iostream>
#include <vector>
#include <map>

using namespace std;

using element = int;
struct NODE{
    element idx, weight;
    NODE* right;
    NODE* left;
};

using PNode = NODE*;
vector<PNode> head, tail;
map <int, pair<PNode, int>> node_table; // Key : Id,   Value : Node Pointer, belt_num

void Print_belt(int belt_num){
    cout << "\n=====================================belt print=====================================\n";
    for(int i = 1; i <= belt_num; i++){
        PNode current_node = head[i]->right;
        cout << "belt" << i << " : ";
        if(current_node->idx == 0){//고장난 경우 
            cout << "broken belt"; 
        }
        while(current_node != tail[i]){
            cout << " [ id: " << current_node->idx << " w: " << current_node->weight << "] ";
            current_node = current_node->right;
        }
        cout << "\n";
    }
    cout << "====================================================================================\n";
}


PNode CreatNode(int id, int w){
    PNode node = (PNode)malloc(sizeof(NODE));
    node->idx = id;
    node->weight = w;
    node->right = NULL;
    node->left = NULL;

    return node;
}

void Insert_left_Tail(int belt_num, int id, int w){
    PNode target = tail[belt_num];
    PNode new_node = CreatNode(id, w);
    new_node->left = target->left;
    new_node->right = target;
    target->left->right = new_node;
    target->left = new_node;

    node_table[id] = {new_node, belt_num};
}

void Remove_node(PNode target){
    target->right->left = target->left;
    target->left->right = target->right;

    node_table.erase(target->idx);
    free(target);
}

void Move_Back(int belt_num){
    PNode target = head[belt_num]->right;

    target->right->left = head[belt_num];
    head[belt_num]->right = target->right;

    target->left = tail[belt_num]->left;
    target->right = tail[belt_num];

    tail[belt_num]->left->right = target;
    tail[belt_num]->left = target;
}

void Move_Group_Front(PNode target_start, int belt_num){
    PNode target_end = tail[belt_num]->left;

    tail[belt_num]->left = target_start->left;
    target_start->left->right = tail[belt_num];

    PNode first = head[belt_num]->right;

    target_start->left = head[belt_num];
    head[belt_num]->right = target_start;

    target_end->right = first;
    first->left = target_end;
}

void Update_table(int target_belt, int move_to){
    PNode current = head[target_belt]->right;
    while(current != tail[target_belt]){
        node_table[current->idx] = {current, move_to};
        current = current->right;
    }
}

void Move_Group_Back(int target_belt, int move_to){
    
    Update_table(target_belt, move_to);

    head[target_belt]->right->left = tail[move_to]->left;
    tail[target_belt]->left->right = tail[move_to];
    
    tail[move_to]->left->right = head[target_belt]->right;
    tail[move_to]->left = tail[target_belt]->left;

    head[target_belt]->right = tail[target_belt];
    tail[target_belt]->left = head[target_belt];
    head[target_belt]->idx = 0;
}

void request_100(int box_num, int belt_num){
    vector <int> id(box_num);
    vector <int> w(box_num);

    for(int i = 0; i < box_num; i++){
        cin >> id[i];
    }
    for(int i = 0; i < box_num; i++){
        cin >> w[i];
    }

    int devide = box_num / belt_num;

    for(int i = 0; i < box_num; i++){
        Insert_left_Tail((i/devide)+1, id[i], w[i]);
    }
}

void request_200(int w, int belt_num){
    long long sum = 0;
    for(int i = 1; i <= belt_num; i++){
        if((head[i]->idx == 0) || (head[i]->right == tail[i])) continue;
        PNode target = head[i]->right;
        if (target->weight > w) {
            Move_Back(i);
        } else {
            sum += target->weight;
            Remove_node(target);
        }

    }

    cout << sum << '\n';
}

void request_300(int target_id){
    if(node_table.find(target_id) == node_table.end()){
        cout << -1 << "\n";
        return;
    }
    Remove_node(node_table[target_id].first);
    cout << target_id << "\n";
}

void request_400(int target_id){
    if(node_table.find(target_id) == node_table.end()){
        cout << -1 << "\n";
        return;
    }
    Move_Group_Front(node_table[target_id].first, node_table[target_id].second);
    cout << node_table[target_id].second << "\n";
}

void request_500(int target_belt, int belt_num){
    if(head[target_belt]->idx == 0){
        cout << -1 << "\n";
        return;
    }
    int move_to = -1;
    for (int i = 1; i < belt_num; i++) {
        int candidate = ((target_belt + i - 1) % belt_num + 1);
        if (candidate == target_belt) continue; // Skip the target belt
        if (head[candidate]->idx != 0) {
            move_to = candidate;
            break;
        }
    }
    if (move_to == -1) {
        cout << -1 << "\n";
        return;
    }

    Move_Group_Back(target_belt, move_to);
    cout << target_belt << "\n";
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int order_num;
    cin >> order_num;
    while(order_num--){
        int request;
        int n , m;
        cin >> request;

        if(request == 100){
            cin >> n >> m; // n : 선물 수     m : 벨트 수

            head.resize(m+1);
            tail.resize(m+1);

            for(int i = 1; i <= m; i++){
                head[i] = (PNode)malloc(sizeof(NODE));
                tail[i] = (PNode)malloc(sizeof(NODE));

                head[i]->idx = 1; //1 : 사용 가능한 상태,     0 : 사용 불가능한 상태
                head[i]->right = tail[i];
                head[i]->left = NULL;
                head[i]->weight = -1; //무효

                tail[i]->idx = 0; //사용하지 않음
                tail[i]->weight = 0; //사용하지 않음
                tail[i]->right = NULL;
                tail[i]->left = head[i];
            }

            request_100(n, m);
        }else if(request == 200){
            int request_w;
            cin >> request_w;
            request_200(request_w, m);

        }else if(request == 300){
            int request_id;
            cin >> request_id;
            request_300(request_id);

        }else if(request == 400){
            int request_id;
            cin >> request_id;
            request_400(request_id);
        }else{//500
            int request_belt;
            cin >> request_belt;
            request_500(request_belt, m);
        }

        //Print_belt(m);
    }

    return 0;
}