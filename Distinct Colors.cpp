#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int colors[200005], distinct[200005], children[200005];

int dfs(int i, int p){
    int ans = 1;
    for(auto j : g[i]){
        if(j != p) ans += dfs(j, i);
    }
    return children[i] = ans;
}

set<int> dfs2(int i, int p){
    int be; set<int> s;
    if(g[i].back() == p) be = g[i].size()-2;
    else be = g[i].size()-1;
    if(be >= 0) s = dfs2(be+1, p);
    for(int k = be; k >= 0; k--){
        if(g[i][k] != p){
            for(int color : dfs2(g[i][k], i)) s.insert(color);
        }
    }
    s.insert(colors[i]);
    distinct[i] = s.size();
    return s;
}

bool compare(int i, int j){
    return children[i] < children[j];
}

int main(){

    int n, a, b;
    cin >> n;
    g.resize(n);

    for(int i = 0; i < n; i++) cin >> colors[i];

    for(int i = 1; i < n; i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    dfs(0, 0);

    for(int i = 0; i < n; i++){
        sort(g[i].begin(), g[i].end(), compare);
    }

    dfs2(0, 0);

    for(int i = 0; i < n; i++){
        cout << distinct[i] << " ";
    }

    return 0;
}