#include <iostream>
#include <map>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    map<string,int> poke_num; // 포켓몬 이름을 통해 도감번호를 검색(시간복잡도: O(1))
    map<int,string> num_poke; // 도감번호를 통해 포켓몬 이름을 검색(시간복잡도: O(1))
    string name;
    for(int i=1;i<=n;i++){
        cin >> name;
        poke_num.insert({name,i});
        num_poke.insert({i,name});
    }
    string fnd;
    for(int i=0;i<m;i++){
        cin >> fnd;
        if(poke_num[fnd]!=0){ // 입력값으로 첫번째 맵에 검색
            cout<<poke_num[fnd]<<'\n';
            continue;
        }
        // 포켓몬 이름으로 검색이 안될 때 도감번호로 검색
        cout<<num_poke[stoi(fnd)]<<'\n';
    }
    
    return 0;
}