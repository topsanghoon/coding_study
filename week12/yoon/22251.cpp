#include <iostream>
#include <vector>

using namespace std;

vector<int> target_text;

vector<vector<int>> changing_map(10, vector<int> (10, 0));
const int seven_segment[10] = {119, 36, 93, 109, 46, 107, 123, 37, 127, 111};

/*
const int seven_segment[10] = {
    0b1110111, // 0
    0b0100100, // 1
    0b1011101, // 2
    0b1101101, // 3
    0b0101110, // 4
    0b1101011, // 5
    0b1111011, // 6
    0b0100101, // 7
    0b1111111, // 8
    0b1101111  // 9
};
*/


void fill_changing_map(){
    for(int i = 0; i < 10; i++){
        for(int j = i + 1; j < 10; j++){
            int _XOR = seven_segment[i] ^ seven_segment[j];
            int change = __builtin_popcount(_XOR);

            changing_map[i][j] = change;
            changing_map[j][i] = change;
        }
    }
}

int answer = 0;
int K, N, original_X;
void DFS(int depth, int left_cost, int current_num){
    if(current_num != original_X && depth == K && current_num <= N && current_num >= 1 && left_cost >= 0) {

        answer++;
        return;
    }
    else if(depth == K || left_cost < 0) return;


    for(int i = 0; i < 10; i++){

        int step_cost = changing_map[target_text[depth]][i];
        if(left_cost - step_cost < 0) continue;

        DFS(depth + 1, left_cost - step_cost, current_num * 10 + i);
    }
}

int main(){

    int P, X;
    cin >> N >> K >> P >> X;
    original_X = X;

    target_text.resize(K, 0);
    fill_changing_map();

    for (int i = K - 1; i >= 0; i--) {
        target_text[i] = X % 10;
        X /= 10;
    }



    for(int i = 0; i < 10; i++){

        int first_step = changing_map[target_text[0]][i];
        DFS(1, P - first_step, i);
    }

    cout << answer;

    return 0;
}