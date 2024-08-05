#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int depth, furthest;
int distances[2][200005];

void dfs(int i, int p, int k, int d){
    distances[d][i] = k;
    if(k > depth){
        depth = k;
        furthest = i;
    }
    for(int j : g[i]){
        if(j != p) dfs(j, i, k+1, d);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b;
    cin >> n;

    g.resize(n);
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    depth = 0; furthest = 0;
    dfs(0, 0, 0, 0);

    depth = 0;
    dfs(furthest, furthest, 0, 0);

    depth = 0;
    dfs(furthest, furthest, 0, 1);

    for(int i = 0; i < n; i++) cout << max(distances[0][i], distances[1][i]) << " ";

    return 0;
}