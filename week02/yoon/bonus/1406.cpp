#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    string text;
    cin >> text;

    stack <char> left;
    stack <char> right;

    for(char c : text){
        left.push(c);
    }

    int n = 0;
    cin >> n;

    for(int i = 0; i< n; i++){
        char temp;
        cin >> temp;

        if (temp == 'P') {
            char x;
            cin >> x;
            left.push(x);
        }
        else if(temp == 'L'){
            if(left.empty()) continue;
            right.push(left.top());
            left.pop();
        }
        else if(temp == 'D'){
            if(right.empty()) continue;
            left.push(right.top());
            right.pop();
        }
        else{//B
            if(left.empty()) continue;
            left.pop();
        }
    }


    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }


    while(!right.empty()){
        cout << right.top();
        right.pop();
    }

    return 0;
}