#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int depth, furthest;


void dfs(int i, int p, int k){
    if(k > depth){
        depth = k;
        furthest = i;
    }
    for(int j : g[i]){
        if(j != p) dfs(j, i, k+1);
    }
}

int main()
{
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
    dfs(0, 0, 0);

    depth = 0;
    dfs(furthest, furthest, 0);

    cout << depth << endl;

    return 0;
}