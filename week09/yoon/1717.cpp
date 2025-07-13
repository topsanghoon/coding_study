#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    int ra = find(a);
    int rb = find(b);
    if(ra != rb) parent[ra] = rb;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    parent.resize(n+1);
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < m; i++){
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;

        if(temp1){
            cout << (find(temp2) == find(temp3) ? "YES" : "NO") << "\n";
        }
        else{
            merge(temp2, temp3);
        }
    }


    return 0;
}