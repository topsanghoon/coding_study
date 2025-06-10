#include <iostream>
#include <string>

using namespace std;

int check(int req[4], int cur[4]){  //조건을 만족하는지 확인하는 함수수
    int is_true = 1;
    for(int i = 0; i < 4; i++){
        if(req[i] > cur[i]) is_true = 0;
    }
    return is_true;
}

int main(){

    int s, p;
    cin >> s >> p;

    string DNA;
    cin >> DNA;

    int requirement[4]; //A, C, G, T 순서
    for(int i = 0; i < 4; i++){
        cin >> requirement[i];
    }

    int cnt = 0;
    int current[4] = {0};
    for(int i = 0; i< p; i++){//초기 윈도우 생성성
        if(DNA[i] == 'A') current[0]++;
        else if(DNA[i] == 'C') current[1]++;
        else if(DNA[i] == 'G') current[2]++;
        else current[3]++;
    }
    cnt += check(requirement, current);
    
    for(int i = p; i < s; i++){
        if(DNA[i] == 'A') current[0]++;
        else if(DNA[i] == 'C') current[1]++;
        else if(DNA[i] == 'G') current[2]++;
        else current[3]++;

        if(DNA[i-p] == 'A') current[0]--;
        else if(DNA[i-p] == 'C') current[1]--;
        else if(DNA[i-p] == 'G') current[2]--;
        else current[3]--;

        cnt += check(requirement, current);
    }

    cout << cnt;

    return 0;
}