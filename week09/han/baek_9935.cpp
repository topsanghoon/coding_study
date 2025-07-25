#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// 문자열 폭발
// https://www.acmicpc.net/problem/9935
int main(void){
    string str;
    cin >> str;
    string bomb;
    cin >> bomb;

    stack<char> stk;
    string answer = "";
    int bombLength = bomb.length();
    int strLength = str.length();
    for(int i = 0; i < strLength; i++){
        stk.push(str[i]);
        if((int)stk.size() < bombLength){
            continue;
        }
        else{
            char stackTop = stk.top();
            char bombEnd = bomb[bombLength - 1];
            bool trueOrFalse = false;
            if(stackTop == bombEnd){
                string temp = "";
                for(int i = 0; i < bombLength; i++){
                    char poping = stk.top();
                    stk.pop();
                    temp += poping;
                    if(poping == bomb[bombLength - 1 - i]){
                        trueOrFalse = true;
                    }
                    else{
                        trueOrFalse = false;
                        break;
                    }
                }
                if(trueOrFalse){

                }
                else{
                    for(int i = (int)temp.length()-1; i >= 0; i--){
                        stk.push(temp[i]);
                    }
                }
            }
        }
    }
    int answerSize = stk.size();
    if(answerSize == 0){
        cout << "FRULA";
        return 0;
    }
    else{
        for(int i = 0; i < answerSize; i++){
            answer += stk.top();
            stk.pop();
        }
        reverse(answer.begin(), answer.end());
        cout << answer;
        return 0;
    }
}