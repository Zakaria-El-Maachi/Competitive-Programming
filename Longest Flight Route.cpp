#include <bits/stdc++.h>

using namespace std;

int n ,m, a, b;
vector<vector<int>> g;
int memo[100005];
vector<int> p;

int dfs(int i){
    if(i == n-1) return 1;
    else if(g[i].size() == 0) return -1e9;
    if(memo[i] != -1) return memo[i];
    int res = -1e9;
    for(int j : g[i]){
        if(res < 1+dfs(j)){
            res = 1+dfs(j);
            p[i] = j;
        }
    }
    return memo[i] = res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(memo, -1, sizeof(memo));
    cin >> n >> m;
    g.resize(n); p.assign(n, -1);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
    }

    dfs(0);

    if(memo[0] < 2) cout << "IMPOSSIBLE";
    else{
        cout << memo[0] << endl;
        a = 0;
        while(a != -1){
            cout << a+1 << " ";
            a = p[a];
        }
    }

    return 0;
}