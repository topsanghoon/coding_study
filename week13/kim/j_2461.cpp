#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int DaysPerMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int DaysPerMonthSum[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};

int MDToDays(int mm, int dd){
    return DaysPerMonthSum[mm-1] + dd;
}


bool compare_asc_start(pair<int,int> p1, pair<int,int> p2){
    if(p1.first==p2.first){
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

bool compare_desc_end(tuple<int,int,int> t1, tuple<int,int,int> t2){
    if(get<1>(t1)==get<1>(t2)){
        return get<0>(t1) > get<0>(t2);
    }
    return get<1>(t1) > get<1>(t2);
}

vector<pair<int,int>> flowers_asc_start;
vector<tuple<int,int,int>> flowers_desc_end;

int main(){

    
    int n;
    cin >> n;

    int a,b,c,d;
    int startDays, endDays;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c >> d;
        startDays = MDToDays(a,b);
        endDays = MDToDays(c,d);

        flowers_asc_start.push_back(make_pair(startDays, endDays));
    }

    sort(flowers_asc_start.begin(), flowers_asc_start.end(), compare_asc_start);

    for(int i=0; i<n; i++){
        //cout << flowers_asc_start[i].first << " " << flowers_asc_start[i].second << " " << i << '\n';
        flowers_desc_end.push_back
            (make_tuple(flowers_asc_start[i].first, flowers_asc_start[i].second, i));
    }

    sort(flowers_desc_end.begin(), flowers_desc_end.end(), compare_desc_end);


    int ans = 0;
    int cur_day = DaysPerMonthSum[2] + 1; //3월 1일

    // for(int i=0;i<n;i++){
    //     cout << flowers_asc_start[i].first << " "
    //     << flowers_asc_start[i].second << " | "
    //     << flowers_desc_end[i].first << " "
    //     << flowers_desc_end[i].second << "\n";
    // }

    int end_idx = 0;
    int start_idx = 0;

    //cout << get<1>(flowers_desc_end[0]) << " " << DaysPerMonthSum[11]<<'\n';

    if(get<1>(flowers_desc_end[0]) <= DaysPerMonthSum[11]){
        // 11월 30일 이전에 모든 꽃이 지는 경우
        cout << 0;
        return 0;
    }

    while(cur_day <= DaysPerMonthSum[11]){

        
        int start = get<0>(flowers_desc_end[end_idx]);
        int end = get<1>(flowers_desc_end[end_idx]);

        if(cur_day < start){
            end_idx++;
            continue;
        }

        //cout << start << " " << end << '\n';

        start_idx = get<2>(flowers_desc_end[end_idx]) + 1;
        cur_day = end;
        end_idx = 0;
        
        //cout << start << " " << end << " " << start_idx << '\n';
        
        ans++;

        if(start_idx>= n){
            continue;
        }

        if(cur_day > DaysPerMonthSum[11]) break;
        
        pair<int,int> next = flowers_asc_start[start_idx];
        //cout << next.first<< " " << next.second << '\n';

        while(next.second <= end) {
            start_idx++;
            next = flowers_asc_start[start_idx];
        } 
        
        if(end < next.first){ // 문제
            cout << 0;
            return 0;
        }

    }

    cout << ans;
    return 0;
}