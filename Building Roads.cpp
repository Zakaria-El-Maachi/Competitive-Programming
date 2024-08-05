#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> visited;

void dfs(int a){
    visited[a] = true;
    for(int b : g[a]){
        if(!visited[b]) dfs(b);
    }
}

int main(){

    int n, m, a, b;
    cin >> n >> m;
    g.resize(n);
    visited.assign(n, false);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    vector<int> comp;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            comp.push_back(i);
            dfs(i);
        }
    }

    cout << comp.size() - 1 << endl;
    for(int i = 1; i < comp.size(); i++){
        cout << comp[0] + 1 << " " << comp[i] + 1 << endl;
    }

    return 0;
}