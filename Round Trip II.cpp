#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> visited;
vector<int> parent;
int cycleStart;
int cycleEnd;

void dfs(int a){
    visited[a] = 1;
    for(int b : g[a]){
        if(cycleStart >= 0) continue;
        if(visited[b] == 0){
            parent[b] = a;
            dfs(b);
        }   
        else if(visited[b] == 1){
            cycleStart = a;
            cycleEnd = b;
        }
    }
    visited[a] = 2;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    g.resize(n);
    parent.assign(n, -1);
    visited.assign(n, 0);
    cycleStart = -1;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
    }
    for(int r = 0; r < n; r++){
        if(visited[r] == 0) dfs(r);
    }

    if(cycleStart >= 0){
        vector<int> c; int k = cycleStart;
        do{
            c.push_back(k);
            k = parent[k];
        } while(k != cycleEnd);
        c.push_back(cycleEnd);
        cout << c.size() + 1 << "\n";
        for(int i = c.size() - 1; i >= 0; i--) cout << c[i] + 1 << " ";
        cout << c.back() + 1;
    }
    else cout << "IMPOSSIBLE";

    return 0;
}