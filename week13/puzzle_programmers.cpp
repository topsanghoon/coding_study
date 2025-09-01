//https://school.programmers.co.kr/learn/courses/30/lessons/340212?language=cpp
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long get_value(vector<int> &diffs , vector<int> &times , int level , int arr_size){
    long long sum=0;
    for(int i=0;i<arr_size;i++){
        if(diffs[i] > level){
            sum += (diffs[i]-level)*(times[i]+times[i-1]);
            sum += times[i];
        }
        else{
            sum += times[i];    
        }
    }
    return sum;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    
    
    int start=1;
    int end=*max_element(diffs.begin(),diffs.end());
    int answer = end;
    int arr_size = diffs.size();
    //cout<<get_value(diffs,times,1,arr_size)<<'\n';
    while(start<=end){
        int mid = (start+end)/2;
        //cout<<"start:"<<start<<" end:"<<end<<" mid:"<<mid<<'\n';
        long long mid_val = get_value(diffs,times,mid,arr_size);
        if(mid_val > limit){
            start = mid+1;   
        }
        else if(limit > mid_val){
            if(mid <answer) answer = mid;
            end=mid-1;
        }
        else{
            answer= mid;
            break;
        }
        //cout<<" mid_val,limit,ans:"<<mid_val<<" "<<limit<<" "<<answer<<'\n';

    }
    
    
    
    return answer;
}