#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

void DFS(int row, int n, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2) {
    if (row == n) {
        ans++;
        return;
    }

    for (int c = 0; c < n; c++) {
        if (col[c] || diag1[row + c] || diag2[row - c + n - 1]) continue;

        col[c] = diag1[row + c] = diag2[row - c + n - 1] = true;
        DFS(row + 1, n, col, diag1, diag2);
        col[c] = diag1[row + c] = diag2[row - c + n - 1] = false;
    }
}

int main() {
    int n;
    cin >> n;

    vector<bool> col(n, false);          
    vector<bool> diag1(2 * n - 1, false); 
    vector<bool> diag2(2 * n - 1, false);  

    DFS(0, n, col, diag1, diag2);

    cout << ans << '\n';
    return 0;
}
