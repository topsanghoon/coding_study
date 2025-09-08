#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

#define INT_MAX 2147483647


using namespace std;

struct compare {
    bool operator()(pair<int,int>p1, pair<int,int>p2){
        if(p1.second == p2.second) return p1.first > p2.first;
        return p1.second > p2.second;
    }
};

struct Node {
    int num;
    int root;
    int min_cost;
    bool seekable;
    
    Node(int n=0, int r=0, int c=0, bool s=false) 
        : num(n), root(r), min_cost(c), seekable(s) {}
};
vector<Node> nodes;
queue<Node> q;
priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
vector<vector<pair<int,int>>> graph;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    nodes = vector<Node>(n+1);
    graph = vector<vector<pair<int,int>>>(n+1);
    
    for(int i=1;i<=n;i++){
        nodes[i] = Node(i,0,INT_MAX,true);
    }
    
    for(int i : gates){
        nodes[i].seekable = false;
        
    }
    
    for(int i : summits){
        nodes[i].root = i;
        nodes[i].min_cost = 0;
        nodes[i].seekable = false;
        q.push(nodes[i]);
    }
    
    for(vector<int> path : paths){
        graph[path[0]].push_back(make_pair(path[1], path[2]));
        graph[path[1]].push_back(make_pair(path[0], path[2]));
    }
    
    while(!q.empty()){
        Node cur = q.front();
        q.pop();
        //cout << cur.num <<": ";
        for(pair<int,int> next : graph[cur.num]){
            
            if(nodes[next.first].seekable == false) continue;
            
            int next_cost = (cur.min_cost < next.second) ? next.second : cur.min_cost;  
            if(next_cost >= nodes[next.first].min_cost) continue;
            
            nodes[next.first].min_cost = next_cost;
            nodes[next.first].root = cur.root;
            q.push(nodes[next.first]);
            //cout << next.first << ": " << cur.root << ", " <<next_cost << '\n';
            
        }
        
    }
    
    for(int i : gates){
        
        for(pair<int,int> p : graph[i]){
                        
            Node node = nodes[p.first];
            int root = node.root;
            
            int cost = (node.min_cost < p.second) ? p.second : node.min_cost;
            pq.push(make_pair(root,cost));
        }
    }
    
    pair<int,int> rc = pq.top();
    
    answer.push_back(rc.first);
    answer.push_back(rc.second);
    
    return answer;
}

