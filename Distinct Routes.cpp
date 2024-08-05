#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> g, capacity;
vector<int> parent;

bool bfs(){
    queue<int> q;
    parent.assign(n, -1);
    q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : g[u]){
            if(parent[v] != -1 || capacity[u][v] == 0) continue;
            parent[v] = u;
            if(v == n-1) return true;
            q.push(v);
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    int a, b;
    cin >> n >> m;
    g.resize(n); capacity.assign(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
        capacity[a-1][b-1] = 1;
    }

    int days = 0;
    while(bfs()){
        days++;
        int cur = n-1;
        while(cur != 0){
            int prev = parent[cur];
            capacity[prev][cur]++;
            capacity[cur][prev]--;
        }
    }

    

    return 0;
}