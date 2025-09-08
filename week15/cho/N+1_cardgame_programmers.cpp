//https://school.programmers.co.kr/learn/courses/30/lessons/258707
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;



int solution(int coin, vector<int> cards) {
    int N=cards.size();
    
    unordered_set<int> hand;
    unordered_set<int> keep;
    
    for(int i=0;i<N/3;i++) hand.insert(cards[i]);
    
    int AddIndex=N/3;
    int round=1;
    while(AddIndex+1 < N){
        keep.insert(cards[AddIndex++]);
        keep.insert(cards[AddIndex++]);
        
        bool check = false;
        
        for(int x:hand){
            auto it=hand.find(N-x+1);
            if(it==hand.end()) continue;
            hand.erase(it);
            hand.erase(hand.find(x));
            round++;
            check=true;
            break;
        }
        
        if(check) continue;
        if(coin>=1){
            for(int x:hand){
                auto it=keep.find(N-x+1);
                if(it==keep.end()) continue;
                keep.erase(it);
                hand.erase(hand.find(x));
                coin -=1;
                round++;
                check=true;
                break;
            }
        }
        if(check) continue;
        if(coin>=2){
            for(int x:keep){
                auto it=keep.find(N-x+1);
                if(it==keep.end()) continue;
                keep.erase(it);
                keep.erase(keep.find(x));
                coin -=2;
                round++;
                check=true;
                break;
            }
        }
        
        if(!check){
            //round++;
            break;
        }
        
    }
    
    
    return round;
}