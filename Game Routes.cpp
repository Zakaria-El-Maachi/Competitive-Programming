#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9+7;
vector<vector<int>> g;
long long memo[100005];

long long dfs(int i){
    if(i == 0) return 1;
    if(memo[i] != -1) return memo[i];
    long long res = 0;
    for(int j : g[i]){
        res = (res + dfs(j))%mod;
    }
    return memo[i] = res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(memo, -1, sizeof(memo));
    int n, m, a, b;
    cin >> n >> m;
    g.resize(n);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[b-1].push_back(a-1);
    }

    cout << dfs(n-1);

    return 0;
}