#include <iostream>
#include <vector>

using namespace std;

void check(int num) {
    for (int k = 2; k < num; k++) {
        int numerator = num - (k * (k - 1)) / 2;
        if (numerator <= 0) break;
        if (numerator % k == 0) {
            int a = numerator / k;
            cout << num << " = ";
            for (int i = 0; i < k - 1; i++) {
                cout << a + i << " + ";
            }
            cout << a + k - 1 << "\n";
            return;
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    


    int n = 0;
    cin >> n;

    int temp = 0;
    while(n--){
        cin >> temp;
        check(temp);
    }

    return 0;
}