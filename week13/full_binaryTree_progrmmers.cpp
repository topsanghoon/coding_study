//https://school.programmers.co.kr/learn/courses/30/lessons/150367?language=cpp




#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string decimalTofullBinary(long long &n){
    string Temp="";
    while(n>0){
        Temp += to_string(n %2);
        n/=2;
    }
    reverse(Temp.begin(),Temp.end());
    
    int len = Temp.size();
    int l = 1;
    while(l <len) l=(l*2)+1;
    Temp = string(l-len,'0') +Temp;
    
    return Temp;
    
}

/*
짝수 루트 트리부분이라서 무조건 1이 되어야 한다는 전제는 잘못 접근 한거임 
bool check_binaryTree(string &n ,int size){
    
    for(int i=1;i<size;i+=2){
        if(n[i]=='0'){
            return false;
        }
    }

    return true;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i=0;i<numbers.size();i++){
        string temp=decimalTofullBinary(numbers[i]);
        bool res = check_binaryTree(temp,temp.size());
        if(res){
            answer.push_back(1);
        }
        else{
            answer.push_back(0);
        }
    }
    
    return answer;
}

*/

//루트가 0이면 자식 부분에 1이 있으면 안됨.  재귀로 트리를 위에서부터 추적 하는데 자식 노드와 루트 노트 비교하면서 잘못 접근하면 바로 false날림

bool check_binaryTree(string &n ,int start,int end){
    
    int mid= (start+end)/2;
    char root = n[mid];
    
    if(start ==end) return true;
    int leftmid= (start+mid-1)/2;
    int rightmid=(mid+end+1)/2;
    if(root == '0'){
        if(n[leftmid]=='1' || n[rightmid]=='1') return false;
    }
    return check_binaryTree(n,start,mid-1) && check_binaryTree(n,mid+1,end);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i=0;i<numbers.size();i++){
        string temp=decimalTofullBinary(numbers[i]);
        bool res = check_binaryTree(temp,0,temp.size()-1);
        if(res){
            answer.push_back(1);
        }
        else{
            answer.push_back(0);
        }
    }
    
    return answer;
}



