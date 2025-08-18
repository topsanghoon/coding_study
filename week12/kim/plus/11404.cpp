#include <iostream>
#include <vector>
using namespace std;
#define MAX_NUM 1000000007

vector<vector<int>> graph;

int main()
{
    int n;
    cin >> n;
    int v;
    cin >> v;
    graph = vector<vector<int>>(n+1,vector<int>(n+1,MAX_NUM));
    for(int i=0;i<=n;i++){
        graph[i][i] = 0;
    }
    int s,e,c;
    for(int i=0;i<v;i++){
        cin >> s >> e >> c;
        if(graph[s][e] > c){
            graph[s][e] = c;
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(graph[i][k] == MAX_NUM) continue;
            for(int j=1;j<=n;j++){
                if(graph[k][j] == MAX_NUM) continue;
                int cand = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], cand);
            }
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << (graph[i][j] == MAX_NUM ? 0 : graph[i][j]) <<" ";
            //cout << graph[i][j]<<" ";
        }
        cout << '\n';
    }

    return 0;
}