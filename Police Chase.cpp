#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> g, capacity;
vector<bool> visited;
vector<pair<int, int>> streets; 
vector<int> parent;
int n;

bool bfs(){
    queue<int> q;
    parent.assign(n, -1);
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : g[u]){
            if(parent[v] != -1 || capacity[u][v] == 0) continue;
            parent[v] = u;
            if(v == n-1) return true;
            q.push(v);
        }
    }
    return false;
}

void dfs(int i){
    visited[i] = true;
    for(int j : g[i]){
        if(capacity[i][j] && !visited[j]) dfs(j);
    }
}

int main(){
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    int m, a, b;
    cin >> n >> m;
    g.resize(n); capacity.assign(n, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
        capacity[a-1][b-1] = capacity[b-1][a-1] = 1;
    }

    int ans = 0;
    while(bool street = bfs()){
        ans++;
        int cur = n-1;
        while(cur != 0){
            int prev = parent[cur];
            capacity[prev][cur] -= 1;
            capacity[cur][prev] = 1;
            cur = prev;
        }
    }

    visited.assign(n , false);
    dfs(0);

    for(int i = 0; i < n; i++){
        if(!visited[i]) continue;
        for(int j : g[i]){
            if(!visited[j] && capacity[i][j] == 0) streets.push_back({i, j});
        }
    }

    cout << ans << "\n";
    for(int i = 0; i < streets.size(); i++){
        cout << streets[i].first+1 << " " << streets[i].second+1 << "\n";
    }

    return 0;
}