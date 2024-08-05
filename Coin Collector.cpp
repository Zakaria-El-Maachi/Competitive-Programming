#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> g1, g2, g3;
vector<bool> visited;
vector<int> sorted, coins;
vector<long long> coins3, memo;

void dfs(int i){
    visited[i] = true;
    for(int j : g1[i])
        if(!visited[j]) dfs(j);
    sorted.push_back(i);
}

void dfs1(int i, int s, long long& ans, vector<int>& c){
    visited[i] = true;
    c[i] = s;
    ans += coins[i];
    for(int j : g2[i])
        if(!visited[j]) dfs1(j, s, ans, c);
}

long long dfs3(int i){
    if(memo[i] != -1) return memo[i];
    long long ans = 0;
    for(int j : g3[i]){
        ans = max(ans, dfs3(j));
    }
    return memo[i] = coins3[i] + ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    g1.resize(n); g2.resize(n); visited.assign(n, false); coins.resize(n);

    for(int& i : coins) cin >> i;

    while(m--){
        cin >> a >> b;
        g1[a-1].push_back(b-1);
        g2[b-1].push_back(a-1);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i);
    }
    reverse(sorted.begin(), sorted.end());
    int counter = 0;
    vector<int> components(n);
    visited.assign(n, false);

    for(int i : sorted){
        if(!visited[i]){
            long long ans = 0;
            dfs1(i, counter, ans, components);
            coins3.push_back(ans);
            counter++;
        }
    }
    g3.resize(counter);

    for(int i = 0; i < n; i++){
        for(int j : g1[i]){
            if(components[i] != components[j]){
                g3[components[i]].push_back(components[j]);
                // cout << components[i] << " " << components[j] << endl;
            }
        }
    }

    memo.assign(counter, -1);
    long long res = 0;

    for(int i = 0; i < counter; i++){
        if(memo[i] == -1){
            res = max(res, dfs3(i));
        }
    }

    cout << res;

    return 0;
}