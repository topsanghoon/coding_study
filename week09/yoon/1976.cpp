#include <iostream>
#include <vector>

using namespace std;

int N, M;
int graph[201]; // 최대 도시 수는 200개

// 부모를 찾는 함수 (경로 압축)
int find(int x) {
    if (graph[x] == x) return x;
    return graph[x] = find(graph[x]);
}

// 두 도시를 같은 집합으로 합침
void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        graph[rootA] = rootB;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        graph[i] = i;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int connected;
            cin >> connected;
            if (connected == 1) {
                merge(i, j);
            }
        }
    }

    // 여행 계획 입력
    vector<int> plan(M);
    for (int i = 0; i < M; ++i) {
        cin >> plan[i];
    }

    // 첫 도시의 루트 찾기
    int root = find(plan[0]);
    for (int i = 1; i < M; ++i) {
        if (find(plan[i]) != root) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
