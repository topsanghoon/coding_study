#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, gahi, danbi;
    cin >> N >> gahi >> danbi;

    if(gahi + danbi - 1 > N) {
        cout << -1;
        return 0;
    }

    vector <int> answer(N, 1);
    int highest = max(gahi, danbi);

    for(int i = N - 1, h = 1; i > N - danbi; i--, h++) answer[i] = h;

    if(gahi == 1) answer[0] = highest;
    else{
        answer[N - danbi] = highest;
        for(int i = N - danbi - 1, h = gahi - 1; h > 1; i--, h--) answer[i] = h;
    }

    for(int i = 0; i < N; i++){
        cout << answer[i] << " ";
    }

    return 0;
}