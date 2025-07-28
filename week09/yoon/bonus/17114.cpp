#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

    vector<int> demention_list(11);
    int size = 1;
    for(int i = 0; i < 11; i++){
        cin >> demention_list[i];
        size *= demention_list[i];
    }

    // vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>> tomato(
    //     m, vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>(
    //         n, vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>(
    //             o, vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>(
    //                 p, vector<vector<vector<vector<vector<vector<vector<int>>>>>>>(
    //                     q, vector<vector<vector<vector<vector<vector<int>>>>>>(
    //                         r, vector<vector<vector<vector<vector<int>>>>>(
    //                             s, vector<vector<vector<vector<int>>>>(
    //                                 t, vector<vector<vector<int>>>(
    //                                     u, vector<vector<int>>(
    //                                         v, vector<int>(
    //                                             w
    //                                         )
    //                                     )
    //                                 )
    //                             )
    //                         )
    //                     )
    //                 )
    //             )
    //         )
    //     ));

    vector<int> jumpsize(11);
    jumpsize[0] = 1;
    for(int i = 1; i < 11; i++){
        jumpsize[i] = ((jumpsize[i-1]) * demention_list[i-1]);
    }

    vector <int> tomato(size); 
    queue <tuple<int, int>> tomato_queue;
    for(int i = 0; i < size; i++){
        cin >> tomato[i];
        if(tomato[i] == 1){
            tomato_queue.push({i, 0});
        }
    }

    int max_cnt = -1;
    while(!tomato_queue.empty()){
        int idx, cur_cnt;
        tie(idx, cur_cnt) = tomato_queue.front();
        tomato_queue.pop();
        
        max_cnt = max(max_cnt, cur_cnt);

        for(int i = 0; i < 22; i++){
            if(demention_list[i/2] == 1) continue;
            int next_idx;
            if(i % 2) {
                next_idx = idx + jumpsize[i / 2];
            }else {
                next_idx = idx - jumpsize[i / 2];
            }

            if(i/2 != 10){
                if((idx/jumpsize[(i/2) + 1]) != (next_idx/jumpsize[(i/2) + 1])) continue;
            }




            // cout << "cur_idx : " << idx << "next_idx : " << next_idx << endl;

            if(next_idx < 0 || next_idx >= size)continue;
            if(tomato[next_idx] != 0) continue;

            // for(int i = 0; i < 4; i++){
            //     for(int j = 0; j < 6; j++){
            //         cout << tomato[i*6 + j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;

            tomato[next_idx] = 1;
            tomato_queue.push({next_idx, cur_cnt + 1});
        }
    }

    for(int i = 0; i < size; i++){
        if(tomato[i] == 0){
            cout << -1;
            return 0;
        }
    }
    cout << max_cnt;

    return 0;
}