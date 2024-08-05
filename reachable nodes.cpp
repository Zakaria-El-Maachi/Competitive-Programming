#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<bool> visited;
vector<int> reach;

int dfs(int u){
    if(visited[u]) return reach[u];
    visited[u] = true;
    int k = 1;
    for(int i : g[u]){
        k += dfs(i);
    }
    return reach[u] = k;
}


int main(){

    int a, b;
    cin >> n >> m;
    g.resize(n);
    visited.assign(n, false);
    reach.assign(n, 1);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i);
    }
    
    for(int i = 0; i < n; i++){
        cout << reach[i] << "\n";
    }

    return 0;
}