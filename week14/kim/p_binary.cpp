#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> binary;

bool isPossible(int st, int ed, bool status){
    int root = (st + ed)/2;
    
    //cout << "start:" << st <<" end: " << ed <<" root: "<< root <<"\n";
   
    if(binary[root] == 1 && !status) return false;
    if(ed <= st) return true;
    
    if(binary[root] == 1){
        return isPossible(st, root-1,status) && isPossible(root+1, ed,status);
    } else {
        return isPossible(st, root-1,false) && isPossible(root+1, ed,false);
    }
    
    
    
    return true;
}



vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(long long num :  numbers){
    long long tmp = num;
        int len = 0;
        int all_len = 1;

        for(len = 0; tmp>0; tmp/=2, len++); // numbers의 2진수 길이
        //cout << len << " ";
        while(len >= all_len) all_len <<= 1;
        binary = vector<int>(all_len-1);

        for(int i = binary.size()-1; i>=0; i--){
            binary[i] = num & 1;
            num >>= 1;
        }
        

        int root = binary.size()/2;
        
        answer.push_back(isPossible(0,(binary.size()-1),true) ? 1 : 0);
    }
    
    return answer;
}

//1011111