#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int up[200005][26];

void dfs(int i, int p){
    up[i][0] = p;

    for(int k = 1; k < 26; k++){
        up[i][k] = up[up[i][k-1]][k-1];
    }

    for(int j : g[i]){
        if(j != p) dfs(j, i);
    }
}

int parent(int i, int k){
    int ans = i;
    for(int j = 25; j >= 0; j--){
        if((1 << j) <= k){
            ans = up[ans][j];
            k -= (1 << j);
        }
    }
    return ans;
}

int main(){

    int n ,q, a, b, y;
    cin >> n >> q;
    g.resize(n+1);

    for(int i = 1; i < n; i++){
        cin >> b;
        g[b].push_back(i+1);
    }

    dfs(1, 0);

    for(int i = 0; i < q; i++){
        cin >> a >> b;
        y = parent(a, b);
        if(y == 0) cout << -1 << "\n";
        else cout << y << "\n";
    }

    return 0;
}