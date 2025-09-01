//https://school.programmers.co.kr/learn/courses/30/lessons/340212

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// diffs_len은 배열 diffs의 길이입니다.
// times_len은 배열 times의 길이입니다.

int getTime(int level, int diff, int prev_time, int cur_time){
    
    int num = (level >= diff) ? 0 : diff-level;
    return num*(prev_time + cur_time) + cur_time;
    
}

bool canEnter(int level, long long limit, int diffs[], size_t diffs_len, int times[], size_t times_len) {
    
    // O(N) 최대 3000000
    long long sum = times[0];
    for(int i=1;i<diffs_len;i++){
        sum += getTime(level, diffs[i], times[i-1], times[i]);
        //printf("level: %d, sum: %d, limit: %d\n", level, sum, limit);
        if(sum > limit) return false;
    }
    
    return true;
}

int solution(int diffs[], size_t diffs_len, int times[], size_t times_len, long long limit) {
    int answer = 0;
    
    int start = 1;
    int end = 0;
    for(int i=0;i<diffs_len;i++){
        if(end < diffs[i]) end = diffs[i];
    }
    
    
    int middle; // cur_level
    while(start <= end) {
        middle = (start+end)/2;
        
        if(canEnter(middle, limit, diffs, diffs_len, times, times_len)){
            end = middle-1;
            answer = middle;
            
        } else {
            start = middle+1;
            
        }
    }
    
    return answer;
}

// diff -> 퍼즐 난이도 
// time_cur -> 현재 소요시간
// time_prev -> 이전 퍼즐 소요시간