#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> relationship;
vector<bool> visited;

void dfs(int depth, int current){ 
    if(depth == 5){//하나라도 찾으면 끝
        cout << "1";
        exit(0);
    }
    for(int i : relationship[current]){ //현재 노드가 친구인 노드들을 순회하면서
        if(visited[i] == true)continue; //만약 방문했었다면 넘어가고
        visited[i] = true; //방문했음을 알리고

        dfs(depth+1, i);//탐색
        
        visited[i] = false;
    }
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int M;
    cin >> N >> M;
    
    relationship.resize(N);
    visited.resize(N, false);

    for(int i = 0; i < M; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        relationship[temp1].push_back(temp2);  //그래프를 만듦
        relationship[temp2].push_back(temp1);  //그래프는 양방향
    }

    for(int i = 0; i < N; i++){  //양방향임으로 서로를 가르키지 않게 하기 위해 visited를 사용
        visited[i] = true;
        dfs(1, i);
        visited[i] = false;
    }

    cout << "0";
    
    return 0;
}