#include <iostream>
#include <vector>

using namespace std;

// 컨베이어 벨트 위의 로봇
// https://www.acmicpc.net/problem/20055

int N, K;
int convey[200+1][2] = {0,};

// 오른쪽으로 움직이기
// 컨베이어와 로봇이 동시에 움직인다
void moveConvey(){
    int last = convey[2*N][0];
    int lastRobotStatus = convey[2*N][1];
    for(int i = 2*N; i > 1; i--){
        if(i < N){
            convey[i][0] = convey[i-1][0];
            convey[i][1] = convey[i-1][1];
        }
        else {
            convey[i][0] = convey[i-1][0];
            convey[i][1] = 0;
        }
    }
    convey[1][0] = last;
    convey[1][1] = lastRobotStatus;
}

// 로봇 움직이기
// 이동하려는 칸에 로봇이 없으며 그 칸의 내구도는 1 이상 남아야 한다.
void moveRobot(){
    for(int i = N; i >= 1; i--){
        if(convey[i][1] == 1 && convey[i+1][1] == 0 && convey[i+1][0] >= 1){
            convey[i][1] = 0;
            convey[i+1][1] = 1;
            convey[i+1][0] -= 1;
        }
    }
}

// 로봇 생성하기
// 올리는 위치 칸의 내구도가 0이 아니면 로봇을 올린다.
void createRobot(){
    if(convey[1][0] != 0){
        convey[1][0] -= 1;
        convey[1][1] = 1;
    }
}

// 컨베이어 검사
bool checkConvey(){
    int count = 0;
    for(int i = 1; i <= 2*N; i++){
        if(convey[i][0] == 0) count += 1;
    }
    if(count >= K) return true;
    return false;
}

int main(void){
    cin >> N >> K;
    for(int i = 1; i <= 2*N; i++){
        int temp;
        cin >> temp;
        convey[i][0] = temp;
    }
    // moveConvey();
    // for(int i = 1; i <= 2*N; i++){
    //     cout << convey[i][0] << " ";
    // }
    int answer = 0;
    while(true){
        answer += 1;
        moveConvey();
        moveRobot();
        createRobot();
        if(checkConvey()) break;
    }
    cout << answer;
}