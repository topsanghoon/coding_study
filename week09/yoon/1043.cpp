#include <iostream>
#include <vector>

using namespace std;

vector<int> group;

int find(int x){
    if(group[x] == x) return x;
    return group[x] = find(group[x]);
}

void merge(int a, int b){

    int pa = find(a);
    int pb = find(b);
    if(pa != pb) group[pa] = pb;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    group.resize(N+1);
    for(int i = 0; i <= N; i++) group[i] = i;

    int know_truth;
    cin >> know_truth;

    vector<int> truth;
    for(int i = 0 ; i < know_truth; i++) {
        int temp;
        cin >> temp;
        truth.push_back(temp);
        merge(temp, 0);
    }

    vector<vector<int>> party_list(M);
    for(int i = 0; i < M; i++){
        int temp;
        cin >> temp;
        while(temp--){
            int who;
            cin >> who;
            party_list[i].push_back(who);
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 1; j < party_list[i].size(); j++) {
            merge(party_list[i][0], party_list[i][j]);
        }
    }

    for (int i = 0; i < know_truth; i++) {
        merge(truth[i], 0);
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        bool can_lie = true;
        for (int person : party_list[i]) {
            if (find(person) == find(0)) {
                can_lie = false;
                break;
            }
        }
        if (can_lie) cnt++;
    }
    cout << cnt;

    return 0;
}