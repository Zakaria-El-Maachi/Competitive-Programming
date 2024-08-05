#include <bits/stdc++.h>

using namespace std;

long long memo[21][1200000];

int main(){
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    memset(memo, 0, sizeof(memo));
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[b-1].push_back(a-1);
    }
  
    memo[0][1] = 1;

    int sub = (1 << n), last = (1 << (n-1)), mod = 1e9+7;
    for(int i = 2; i < sub; i++){
        
        if(!(i & 1)) continue;
        if((i & last) && i != sub-1) continue;

        for(int k = 0; k < n; k++){
            int r = (1 << k);
            if(r & i){
                for(int prev : g[k]) memo[k][i] += memo[prev][i-r];
                memo[k][i] %= mod;
            }
        }
    }

    cout << memo[n-1][sub-1];

    return 0;
}