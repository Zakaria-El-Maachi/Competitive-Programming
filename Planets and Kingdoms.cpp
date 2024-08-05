#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> g1, g2;
vector<bool> visited;
vector<int> sorted;

void dfs(int i){
    visited[i] = true;
    for(int j : g1[i])
        if(!visited[j]) dfs(j);
    sorted.push_back(i);
}
void dfs1(int i, int s, vector<int>& c){
    visited[i] = true;
    c[i] = s;
    for(int j : g2[i])
        if(!visited[j]) dfs1(j, s, c);
}

int main(){

    int n, m, a, b;
    cin >> n >> m;
    g1.resize(n); g2.resize(n), visited.assign(n, false);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g1[a-1].push_back(b-1);
        g2[b-1].push_back(a-1);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i);
    }

    visited.assign(n, false);
    reverse(sorted.begin(), sorted.end());
    vector<int> components(n);
    int ans = 0;

    for(int i : sorted){
        if(!visited[i]){
            ans++;
            dfs1(i, ans, components);
        }
    }

    cout << ans << "\n";
    for(int i : components) cout << i << "\n";

    return 0;
}