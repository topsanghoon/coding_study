//https://school.programmers.co.kr/learn/courses/30/lessons/181188
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct cmp{
    bool operator()(const vector<int> &a,const vector<int> &b)const{
        return a[1]<b[1];
    }
};

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(),targets.end(),cmp());    
    
    long long e=-1;
    for(auto &n:targets){
        if(n[0] >= e){
            answer++;
            e=n[1];
        }    
        
    }
    
    
    return answer;
}