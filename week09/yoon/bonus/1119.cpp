#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> parent;
int findp(int x)
{ 
    return parent[x] == x ? x : parent[x] = findp(parent[x]); 
}

void uni(int a,int b)
{ 
    a=findp(a);
    b=findp(b); 
    if(a!=b) parent[a]=b; 
}

int main(){
  int n; cin>>n;
  parent.resize(n);
  for(int i=0;i<n;i++) parent[i]=i;

  vector<string> G(n);
  for(int i=0;i<n;i++) cin>>G[i];

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(G[i][j]=='Y') uni(i,j);

  unordered_map<int, vector<pair<int,int>>> comp; 


  int cnt_line = 0;
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      if(G[i][j]=='Y'){
        cnt_line++;
        int r = findp(i);
        comp[r].push_back({i,j});
      }

  int cnt_group = comp.size();
  int total_surplus = 0;
  for(auto &kv : comp){
    int sz = 0;
    unordered_set<int> nodes;
    for(auto &e : kv.second){
      nodes.insert(e.first);
      nodes.insert(e.second);
    }
    sz = nodes.size();
    int edges = kv.second.size();
    total_surplus += edges - (sz - 1);
  }

  if(cnt_line < n - 1 || total_surplus < cnt_group - 1){
    cout << -1;
  } else {
    cout << cnt_group - 1;
  }
}