#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

//문제분석
//문제를 그냥 단순히 접근하면 왔던곳을 다시 방문해야 되는 문제가 생긴다.
//이런 경우에는 방문한 곳을 다시 방문하지 않도록 하는 방법이 필요하다. 
//재방문을 하지 않기 위해서는 특정 지점 방문시 그 지점의 물의 양이 최대 이미 수렴함을 보장해야 한다.  
//해당 지점의 물의 양이 최대 수렴함을 보장하기 위해서는 2가지 조건을 만족해야한다.
//1. 인접 지점 중 해당 지점 보다 높은 곳을 먼저 방문한다.
//2. 인접 지점 중 해당 지점과 높이가 같은 곳 중 물의 양이 많은 곳을 먼저 방문한다.
//전형적인 우선 순위 큐문제이다.
//그래프 탐색이 되 높이가 높은 지점을 먼저(1번 조건), 높이가 같을 경우 BFS를 따라 방문(2번 조건)
//물은 기본적으로 높이가 같거나 낮은 곳으로만 확산한다.
//
//N\in[1,2000], X\in[1,2N], x,y\in[1,N]
//=====================================================================
//해결전략
//1.
//=====================================================================
//필요자료형
//변수
//
//함수
//
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    int N,X,x,y;
    cin >> N >> X >> x >> y;
    vector<vector<int>> heights(N, vector<int>(N,0));
    vector<vector<int>> waters(N, vector<int>(N,0));
    vector<vector<bool>> visited(N, vector<bool>(N,false));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> heights[i][j];

    priority_queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push(make_pair(make_pair(heights[x-1][y-1],X),make_pair(x-1,y-1)));
    waters[x-1][y-1] = X;
    visited[x-1][y-1]=true;

    while(!q.empty()){
        int i = q.top().second.first;
        int j = q.top().second.second;
        q.pop();

        if(waters[i][j] <= 1) continue;

        for(int k=0; k<4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
            if(visited[ni][nj]) continue;

            if(heights[i][j] == heights[ni][nj]){
                waters[ni][nj] = waters[i][j]-1;
                visited[ni][nj]=true;
                q.push(make_pair(make_pair(heights[ni][nj],waters[ni][nj]),make_pair(ni,nj)));
            }
            else if(heights[i][j] > heights[ni][nj]){
                waters[ni][nj] = X;
                visited[ni][nj]=true;
                q.push(make_pair(make_pair(heights[ni][nj],waters[ni][nj]),make_pair(ni,nj)));
            }
        }
    }

    int result(0);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if (waters[i][j] > 0) result++;

    cout << result << endl;
}


/*
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, X, x, y;
    cin >> N >> X >> x >> y;
    vector<vector<int>> heights(N, vector<int>(N));
    vector<vector<int>> waters(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> heights[i][j];

    // {water height, x, y}
    priority_queue<tuple<int, int, int>> q;
    
    waters[x - 1][y - 1] = X;
    q.push({X, x - 1, y - 1});

    while (!q.empty()) {
        int w, i, j;
        tie(w, i, j) = q.top(); q.pop();

        // 더 적은 물로 오면 무시
        if (waters[i][j] > w) continue;

        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
            if(w == 1)continue;
            int next_water = 0;
            if (heights[i][j] > heights[ni][nj]) {
                next_water = X;
            } else if (heights[i][j] == heights[ni][nj] && w > 1) {
                next_water = w - 1;
            } else continue;

            if (waters[ni][nj] < next_water) {
                waters[ni][nj] = next_water;
                q.push({next_water, ni, nj});
            }
        }
    }

    int result = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (waters[i][j] > 0)
                ++result;

    cout << result << '\n';
}
*/