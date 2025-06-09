#include <iostream>
#include <map>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    map<string,int> poke_num;
    map<int,string> num_poke;
    string name;
    for(int i=1;i<=n;i++){
        cin >> name;
        poke_num.insert({name,i});
        num_poke.insert({i,name});
    }
    string fnd;
    for(int i=0;i<m;i++){
        cin >> fnd;
        if(poke_num[fnd]!=0){
            cout<<poke_num[fnd]<<'\n';
            continue;
        }
        cout<<num_poke[stoi(fnd)]<<'\n';
    }
    
    return 0;
}