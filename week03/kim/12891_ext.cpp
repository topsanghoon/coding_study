#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool compare();

int arr[4] = {0};
int marr[4];

int main() {

    int s,p;
    cin >> s >> p;
    
    string str;
    cin >> str;

  
    unordered_map<char,int> alp; // 'A C G T'를 인덱스로 변환하기위해 map 사용
    queue<char> q;
    
    alp['A'] = 0;
    alp['C'] = 1;
    alp['G'] = 2;
    alp['T'] = 3;

    for(int i=0;i<4;i++){
        cin >> marr[i];
    }

    int ans = 0;
    
    for(int i=0;i<p;i++){
        q.push(str[i]);
        arr[alp[str[i]]]++;
    }

    
    if(compare()){
       ans++; 
    }
    
    for(int i=p;i<s;i++){
        char qfront = q.front();
        q.pop();
        arr[alp[qfront]]--;
        q.push(str[i]);
        arr[alp[str[i]]]++;
        if(compare()){
           ans++; 
        }
    }
    cout<<ans<<'\n';
    
    return 0;  
}

bool compare(){
    
    bool comp = true;
    for(int i=0;i<4;i++){
        if(arr[i] < marr[i]){
            comp = false;
        }
    }
    return comp;
}