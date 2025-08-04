#include <iostream>
#include <vector>

using namespace std;

int main(){

    int H, W, N, M;
    cin >> H >> W >> N >> M;

    int col = ((W-1) /(M + 1)) + 1;
    int row = ((H-1) / (N + 1)) + 1;

    cout << col * row;


    return 0;
}