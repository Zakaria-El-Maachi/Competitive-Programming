#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int up[200005][26];
int in[200005], out[200005];
int depth[200005];
int counter = 0;

void dfs(int i, int p, int d){
    depth[i] = d;
    in[i] = ++counter;
    up[i][0] = p;

    for(int k = 1; k < 26; k++){
        up[i][k] = up[up[i][k-1]][k-1];
    }

    for(int j : g[i]){
        if(j != p) dfs(j, i, d+1);
    }
    out[i] = ++counter;
}

bool is_parent(int a, int b){
    return in[a] <= in[b] && out[a] >= out[b];
}

int lca(int a, int b){
    if(is_parent(a, b)) return a;
    else if(is_parent(b, a)) return b;
    else{
        for(int k = 25; k >= 0; k--){
            if(!is_parent(up[a][k], b)) a = up[a][k];
        }
        return up[a][0];
    }
}

int main(){

    int n ,q, a, b, y;
    cin >> n >> q;
    g.resize(n+1);

    for(int i = 1; i < n; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 1, 0);

    for(int i = 0; i < q; i++){
        cin >> a >> b;
        cout << depth[a] + depth[b] - 2*depth[lca(a, b)] << "\n";
    }

    return 0;
}