#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> tmp;
queue<pair<int,int>> melt;

int sum = 0;
int ny[4] = {1,-1,0,0};
int nx[4] = {0,0,1,-1};
int sz;

void spin(int y, int x, int n) // O(1000)
{    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp[j][n-i-1] = graph[i+y][j+x];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i+y][j+x] = tmp[i][j];
        }
    }
}

void find_ice() // O(4000)
{
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            int ice_num = 0;
            int nexty, nextx;
            for(int k=0;k<4;k++){
                
                nexty = i+ny[k];
                nextx = j+nx[k];
                if(!(0<=nexty && nexty<sz)) continue;
                if(!(0<=nextx && nextx<sz)) continue;
                if(graph[nexty][nextx]==0) continue;
                ice_num++;

            }
            if(ice_num>=3) continue;
            if(graph[i][j] == 0) continue;
            melt.push(make_pair(i,j));
        }
    }
    while(!melt.empty()){
        pair<int,int> qfront = melt.front();
        graph[qfront.first][qfront.second]--;
        melt.pop();
    }
}

void fire_stome(int div) //O(1000)
{

    int n = sz/div;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            spin(i*div,j*div, div); 
            //cout << i*div<<" "<<j*div<<" "<<div<<'\n';
        }
    }
}

int get_add()
{
    int sum = 0;
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            sum+=graph[i][j];
        }
    }
    return sum;
}

int bfs(int y, int x, vector<vector<bool>>& visited)
{
    int sum = graph[y][x] != 0;
    

    queue<pair<int,int>> q;
    visited[y][x] = true;
    q.push(make_pair(y,x));

    while(!q.empty())
    {
        pair<int,int> qfront = q.front();
        q.pop();

        int nexty, nextx;
        for(int i=0;i<4;i++)
        {
            nexty = qfront.first+ny[i];
            nextx = qfront.second+nx[i];

            if(!(0<=nexty && nexty<sz)) continue;
            if(!(0<=nextx && nextx<sz)) continue;
            if(visited[nexty][nextx]) continue;
            if(graph[nexty][nextx] == 0) continue;

            sum++;
            q.push(make_pair(nexty,nextx));
            visited[nexty][nextx] = true;

        }
    }

    return sum;
}
int get_big_ice()
{
    int mx = 0;
    vector<vector<bool>> visited = 
        vector<vector<bool>>(sz,vector<bool>(sz,false));
    
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            if(visited[i][j]) continue;
            
            
            mx = max(mx,bfs(i,j,visited));

        }
    }
    return mx;
}
int main()
{
    int n,q;
    cin >> n >> q;

    sz = 1<<n;
    graph = vector<vector<int>>(sz,vector<int>(sz,0));

    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            cin >> graph[i][j];
        }
    }

    int l;
    for(int i=0;i<q;i++){ //1000
        cin >> l;
        tmp = vector<vector<int>>(1<<l,vector<int>(1<<l,0));
        fire_stome(1<<l); //1000000
        find_ice();
    }
    cout << get_add()<<'\n';
    cout << get_big_ice() << '\n';

    // for(int i=0;i<sz;i++){
    //     for(int j=0;j<sz;j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout<<'\n';
    // }

    return 0;
}

// 1000000