#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n;

    vector <int> arr(n);
    int temp= 0;
    for(int i = 0; i< n; i++) cin >> temp, arr[i] = temp;

    sort(arr.begin(), arr.end());
    cin >> m;

    while(m--){
        cin >> temp;
        cout << upper_bound(arr.begin(),arr.end(), temp) - lower_bound(arr.begin(), arr.end(), temp) << " ";
    }

    return 0;
}



















// int main(){

//     cin.tie(0);
//     ios::sync_with_stdio(false);
    
//     int n, m;
//     cin >> n;

//    map <int, int> map1;
//     while(n--){
//         int temp = 0;
//         cin >> temp;
//         if(map1[temp] >= 1){
//             map1[temp]++;
//         }
//         else map1[temp] = 1;
//     }

//     cin >> m;
//     while(m--){
//         int temp = 0;
//         cin >> temp;
        
//         cout << map1[temp] << " ";
//     }

//     return 0;
// }






// int main(){

//     cin.tie(0);
//     ios::sync_with_stdio(false);
    
//     int n, m;
//     cin >> n;

//     unordered_map <int, int> map;
//     while(n--){
//         int temp = 0;
//         cin >> temp;
//         if(map[temp] >= 1){
//             map[temp]++;
//         }
//         else map[temp] = 1;
//     }

//     cin >> m;
//     while(m--){
//         int temp = 0;
//         cin >> temp;
        
//         cout << map[temp] << " ";
//     }

//     return 0;
// }