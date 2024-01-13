#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
int N, M;
int u, v;
int countConnect = 0;

void input(){
    cin >> N >> M;
    visited.resize(N + 1, false);
    graph.resize(N + 1);
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int node){
    visited[node] = true;
    for(int neighbor : graph[node]){
        if(!visited[neighbor]){
            dfs(neighbor);
        }
    }
}

void solve(){
    for(int node = 1; node <= N; node++){
        if(!visited[node]){
            dfs(node);
            countConnect++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    solve();
    cout << countConnect;
    return 0;
}
