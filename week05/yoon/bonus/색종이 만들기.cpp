#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> paper;

int white = 0, color = 0;

bool Is_same(int size, int r, int c){

    int first = paper[r][c];
    if(size != 1) {
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(first != paper[r + i][c + j]) return false;
            }
        }
    }

    if(first == 0) white++;
    else color++;

    return true;
}

void cut(int size, int r, int c){

    if(Is_same(size, r, c)) return;

    int size_cut = size / 2;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cut(size_cut, r + i * size_cut, c + j * size_cut);
        }
    }
}


int main(){

    int n = 0;
    cin >> n;

    paper.resize(n);
    for(int i = 0; i < n; i++) paper[i].resize(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> paper[i][j];
        }
    }

    cut(n, 0, 0);

    cout << white << "\n" << color;

    return 0;
}