#include <iostream>
#include <string>
#include <stack>
#include <deque>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    string boom;
    cin >> boom;
    deque<char> deq;
    stack<char> buf;

    for(int i=0;i<s.size();i++){
        deq.push_back(s[i]);

        int idx = boom.size()-1;
        while(idx>=0 && !deq.empty() && boom[idx]==deq.back()){
            buf.push(deq.back());
            deq.pop_back();
            idx--;
        }
        if(idx<0){
            while(!buf.empty()) buf.pop(); 
            continue;
        } 
        
        while(!buf.empty()){
            deq.push_back(buf.top());
            buf.pop();
        }
        

    }
    if(deq.empty()){
        cout << "FRULA" << '\n';
        return 0;
    }
    while(!deq.empty()){
        cout<<deq.front();
        deq.pop_front();
    }
    cout<<'\n';
    return 0;
}