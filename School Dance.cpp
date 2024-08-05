#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<vector<int>> g, capacity;
vector<int> parent;

bool bfs(){
    parent.assign(n+m+2, -1);
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        // cout << u << endl;
        q.pop();
        for(int v : g[u]){
            if(parent[v] != -1 || capacity[u][v] == 0) continue;
            parent[v] = u;
            if(v == n+m+1) return true;
            q.push(v);
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    int a, b;
    cin >> n >> m >> k;

    g.resize(n+m+2);
    capacity.assign(n+m+2, vector<int>(n+m+2, 0));

    for(int i = 0; i < k; i++){
        cin >> a >> b;
        g[a].push_back(n+b);
        g[n+b].push_back(a);
        capacity[a][n+b] = 1;
    }
    for(int i = 1; i <= n; i++){
        g[0].push_back(i);
        g[i].push_back(0);
        capacity[0][i] = 1;
    }
    for(int i = 1; i <= m; i++){
        g[n+i].push_back(n+m+1);
        g[n+m+1].push_back(n+i);
        capacity[n+i][n+m+1] = 1;
    }

    int r = 0;
    while(bfs()){
        r++;
        int cur = n+m+1;
        // cout << r << endl;
        while(cur != 0){
            int prev = parent[cur];
            capacity[prev][cur]--;
            capacity[cur][prev]++;
            cur = prev;
        }
    }

    cout << r << "\n";
    for(int i = 1; i <= n; i++){
        for(int j : g[i]){
            if(j != 0 && capacity[i][j] == 0){
                cout << i << " " << j-n << "\n";
                break;
            }
        }
    }

    return 0;
}