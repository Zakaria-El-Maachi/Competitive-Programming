#include <bits/stdc++.h>

#define int long long

using namespace std;

long long MAX = 1e9+7;
int fact[signed(2e6+6)], inverse[signed(2e6+6)];


int inv(int x){
    int ans = 1;
    int b = MAX - 2;
    while(b > 0){
        if(b&1) ans = ans * x % MAX;
        x = x * x % MAX;
        b >>= 1;
    }
    return ans;
}

int combination(int i, int j){
    if(j > i) return 0;
    return (((fact[i] * inverse[j]) % MAX) * inverse[i-j]) % MAX;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, x, y;
    cin >> n >> m;
    vector<pair<int, int>> g(m+1);

    fact[0] = 1;
    inverse[0] = 1;

    for(int i = 1; i < 2*n+3; i++){
        fact[i] = (i*fact[i-1])%MAX;
        inverse[i] = inv(fact[i]);
    }


    for(int i = 0; i < m; i++){
        cin >> y >> x;
        g[i] = {y-1, x-1};
    }

    g[m] = {n-1, n-1};
    sort(g.begin(), g.end());

    vector<int> memo(m+1, 0);

    for(int i = 0; i <= m; i++){
        auto [y0, x0] = g[i];
        memo[i] = combination(y0 + x0, y0);
        for(int j = 0; j < i; j++){
            auto [y1, x1] = g[j];
            if(x1 > x0) continue;
            memo[i] = (memo[i] - memo[j] * combination(y0-y1 + x0-x1, y0-y1))%MAX;
        }
        memo[i] = (memo[i] + MAX)%MAX;
    }

    cout << memo[m];

    return 0;
}