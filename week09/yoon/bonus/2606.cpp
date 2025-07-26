#include <iostream>
#include <vector>

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

    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    for(int i = 1; i <= n; i++) graph[i] = i;

    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        merge(from, to);
    }

    int target = find(1);
    int cnt = 0;
    for(int i = 2; i <=n; i++){
        if(target == find(i))cnt++;
    }

    cout << cnt;

    return 0;
}