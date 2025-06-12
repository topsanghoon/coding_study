#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n = 0;
    cin >> n;

    vector <vector <long long>> class_list;

    for(int i = 0; i < n; i++){
        int id; 
        long long start, end;
        cin >> id >> start >>  end;

        class_list.push_back({start, end});
    }
    sort(class_list.begin(), class_list.end());

    int current_time = 0;
    int max_class = 0;
    priority_queue <int, vector<int>, greater<int>> ing;
    for(vector<long long> cs : class_list){
        if(current_time == cs[0]){ //동시 시작이면
            ing.push(cs[1]);
        }
        else{
            current_time = cs[0];
            while(!ing.empty() && current_time >= ing.top()) ing.pop();
            ing.push(cs[1]);
        }

        max_class = max(max_class, int(ing.size()));
        
    }

    cout << max_class;

    return 0;
}