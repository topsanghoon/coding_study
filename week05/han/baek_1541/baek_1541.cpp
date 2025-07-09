#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;


// 잃어버린 괄호
// https://www.acmicpc.net/problem/1541
string input_s;

vector<string> split(string str, int idx){
    vector<string> result;
    string left = "";
    string right = "";
    for(int i = 0; i < (int)str.length(); i++){
        if(i < idx){
            left += str[i];
        }
        else if(i > idx) right += str[i];
    }
    result.push_back(left);
    result.push_back(right);
    return result;
}

vector<int> parsing(string str){
    vector<char> sVec;
    vector<int> iVec;
    string stringTemp="";
    for(int i = 0; i < (int)str.length(); i++){
        if(isdigit(str[i])){
            stringTemp += str[i];
            if(i == (int)str.length()-1){
                iVec.push_back(stoi(stringTemp));
            }
        }
        else{
            sVec.push_back(str[i]);
            iVec.push_back(stoi(stringTemp));
            stringTemp = "";
        }
    }
    return iVec;
}

vector<int> leftString;
vector<int> rightString;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string number;
    cin >> input_s;

    int min = 0;

    bool isMinus = false;

    try {
        int value = stoi(input_s);
        leftString.push_back(value);
    } 
    catch (const std::invalid_argument& e) {
        
    }

    for(int i = 1; i < (int)input_s.length()-1; i++){
        vector<string> temps;
        if(!isdigit(input_s[i])){
            if(input_s[i] == '-'){
                temps = split(input_s,i);
                string left = temps[0];
                string right = temps[1];
                leftString = parsing(left);
                rightString = parsing(right);
                isMinus = true;
                break;
            }
            else if(input_s[i] == '+'){
                temps = split(input_s,i);
                string left = temps[0];
                string right = temps[1];
                leftString = parsing(left);
                rightString = parsing(right);
            }
        }
    }
    for(int i = 0; i < (int)leftString.size(); i++){
        // cout << leftString[i] << "\n";
        min += leftString[i];
    }
    for(int i = 0; i < (int)rightString.size(); i++){
        // cout << "right: "<< rightString[i] << "\n";
        if(isMinus) min -= rightString[i];
        else min += rightString[i];
    }
    cout << min;
}