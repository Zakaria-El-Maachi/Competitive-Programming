#include <bits/stdc++.h>

using namespace std;
#define int long long

vector<vector<int>> g, capacity;
vector<int> parent;
int n;

int bfs(){
    queue<pair<int, int>> q;
    q.push({0, 1e9+7});
    while(!q.empty()){
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();
        for(int v : g[u]){
            if(parent[v] != -1 || capacity[u][v] == 0) continue;
            int n_flow = min(flow, capacity[u][v]);
            parent[v] = u;
            if(v == n-1) return n_flow;
            q.push({v, n_flow});
        }
    }
    return 0;
}

signed main(){

    int m, a, b, c;
    cin >> n >> m;
    g.resize(n); capacity.assign(n, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
        capacity[a-1][b-1] += c;
    }

    parent.assign(n, -1);
    long long ans = 0;
    while(int flow = bfs()){
        ans += flow;
        int cur = n-1;
        while(cur != 0){
            int prev = parent[cur];
            capacity[prev][cur] -= flow;
            capacity[cur][prev] += flow;
            cur = prev;
        }

        parent.assign(n, -1);        
    }

    cout << ans << endl;

    return 0;
}