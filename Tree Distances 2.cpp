#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int distances[200005];
int children[200005];
long long ans[200005];
int n;

void dfs(int i, int p, int k){
    distances[i] = k;
    for(int j : g[i]){
        if(j != p) dfs(j, i, k+1);
    }
}

int dfs2(int i, int p){
    int ans = 1;
    for(int j : g[i]){
        if(j != p) ans += dfs2(j, i);
    }
    return children[i] = ans;
}

void dfs3(int i, int p){
    for(int j : g[i]){
        if(j != p){
            ans[j] = ans[i] - 2 * children[j] + n;
            dfs3(j, i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    long long sum = 0;
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

    dfs(0, 0, 0);
    dfs2(0, 0);
    for(int i = 0; i < n; i++) ans[0] += distances[i];

    dfs3(0, 0);

    for(int i = 0; i < n; i++) cout << ans[i] << " ";

    return 0;
}