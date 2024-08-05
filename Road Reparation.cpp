#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> parent, ranks;
vector<bool> visited;

void dfs(int i){
    visited[i] = true;
    for(int j : g[i])
        if(!visited[j]) dfs(j);
}

struct edge{
    int a, b, c;
    edge(int a0, int b0, int c0): a(a0), b(b0), c(c0) {}
    bool operator<(edge& other) const{
        return c < other.c;
    }
};

int getParent(int a){
    if(parent[a] == a) return a;
    return parent[a] = getParent(parent[a]);
}

void setUnion(int a, int b){
    a = getParent(a), b = getParent(b);
    if(ranks[a] < ranks[b]) swap(a, b);
    parent[b] = a;
    if(ranks[a] == ranks[b]) ranks[a]++;
}

int main(){

    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    int n, m, a, b, c;
    cin >> n >> m;
    g.resize(n); visited.assign(n, false);
    vector<edge> edges;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.push_back(edge(a, b, c));
    }

    dfs(0);
    for(int i = 1; i < n; i++){
        if(!visited[i]){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    parent.resize(n);
    for(int i = 0; i < n; i++) parent[i] = i;
    ranks.assign(n, 0);

    sort(edges.begin(), edges.end());
    long long ans = 0;

    for(edge e : edges){
        if(getParent(e.a) != getParent(e.b)){
            ans += e.c;
            setUnion(e.a, e.b);
        }
    }

    cout << ans;    

    return 0;
}