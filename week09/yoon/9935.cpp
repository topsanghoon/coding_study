#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){

    string text;
    cin >> text;
    int text_len = text.size();

    string bomb;
    cin >> bomb;
    int bomb_len = bomb.size();

    stack <char> left, right;
    for(int i = 0; i < text.size(); i++){
        left.push(text[i]);
    }

    while(!left.empty()){
        char c = left.top(); left.pop();
        right.push(c);

        while(!right.empty()){
            stack <char> temp;
            bool must_bomb = true;

            for(int i = 0; i < bomb_len; i++){
                if(!right.empty() && right.top() == bomb[i]){
                    temp.push(right.top());
                    right.pop();
                    continue;
                }
                must_bomb = false;
                break;
            }

            if(must_bomb) continue;
            while(!temp.empty()){
                right.push(temp.top());
                temp.pop();
            }
            break;
        }
    }

    if(right.empty()) cout << "FRULA";
    else{
        while(!right.empty()){
            cout << right.top();
            right.pop();
        }
    }

    return 0;
}