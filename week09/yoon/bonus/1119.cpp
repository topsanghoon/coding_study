#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector <int> graph;
int find(int x){
    if(graph[x] == x) return x;
    return graph[x] = find(graph[x]);
}

void merge(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa != pb) graph[pa] = pb;
}

int main(){

    int n;
    cin >> n;
    graph.resize(n);

    for(int i = 0; i < n; i++)graph[i] = i;

    vector <string> connected (n);
    for(int i = 0; i < n; i++) {
        cin >> connected[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(connected[i][j] == 'Y') merge(i, j);
        }
    }  

    unordered_map <int, int> group;
    int cnt_group = 0;
    //몇개의 그룹이 있고, 각각 몇개의 선을 가지고 있는지 확인
    for(int i = 0; i < n; i++){
        int temp = find(i);
        if(group.find(temp) == group.end()){
            group[temp] = 0;
            cnt_group++;
        }
        group[temp]++;
    }

    int necessary = cnt_group - 1;
    for (auto& [rep, size] : group) {
        if(size == 1 && cnt_group > 1){
            cout << -1;
            return 0;
        }
        necessary += (size - 1);
        //cout << size << endl;
    }

    int cnt_line = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(connected[i][j] == 'Y') cnt_line++;
        }
    }

    //cout << cnt_line << "  " << necessary << endl;

    if(necessary <= cnt_line) cout << (cnt_group - 1);
    else cout << -1;
     

    return 0;
}