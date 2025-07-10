#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct node{
    int y,cost;
};

// struct res{
//     int max_cost,last_node;
// };
vector<vector<node>> tree;
queue<node> q;
vector<bool> visited;



node bfs(int start_node){
    queue<node> q;
    visited.assign(tree.size(), false);

    q.push({start_node, 0});
    visited[start_node] = true;

    node max_element = {start_node, 0};   
    
    while (!q.empty()) {
        node curr = q.front();
        q.pop();

        if (curr.cost > max_element.cost) {
            max_element = curr;
        }
        
        for (int i=0; i<tree[curr.y].size(); i++) {
            if(visited[tree[curr.y][i].y]) continue;
            q.push({tree[curr.y][i].y , curr.cost + tree[curr.y][i].cost});
            visited[tree[curr.y][i].y] =true;   
    }
    
}
    return max_element;
}    



int main() {
    int N;
    cin >> N;

    tree.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        int tmp_x;
        cin >> tmp_x;
        while (true) {
            int tmp_y, cost;
            cin >> tmp_y;
            if (tmp_y == -1) break;
            cin >> cost;
            tree[tmp_x].push_back({tmp_y, cost});
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 0; j < tree[i].size(); j++) {
    //         cout << "(" << tree[i][j].y << ", " << tree[i][j].cost << ") ";
    //     }
    //     cout << '\n';
    // }
    node ans;
    node fin;
    ans=bfs(1); // 1번 노드 , cost_sum=0 매개변수로 전달   결과는 최종 노드, cost_sum 값
    fin=bfs(ans.y);
    cout<<fin.cost;
    return 0;
}