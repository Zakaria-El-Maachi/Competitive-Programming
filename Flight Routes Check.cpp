#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g1, g2;
vector<bool> visited;
vector<int> sorted;

void dfs1(int i){
    visited[i] = true;
    for(int j : g1[i]){
        if(!visited[j]) dfs1(j);
    }
    sorted.push_back(i);
}
void dfs2(int i){
    visited[i] = true;
    for(int j : g2[i]){
        if(!visited[j]) dfs2(j);
    }
}

int main(){

    int n, m, a, b;
    cin >> n >> m;
    g1.resize(n), g2.resize(n), visited.assign(n, false);
    
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g1[a-1].push_back(b-1);
        g2[b-1].push_back(a-1);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs1(i);
    }

    int ans = 0;
    visited.assign(n, false);
    reverse(sorted.begin(), sorted.end());
    vector<int> comp;
    
    for(int i : sorted){
        if(!visited[i]){
            comp.push_back(i);
            dfs2(i);
            ans++;
        }

        if(ans > 1) break;
    }
    
    if(ans > 1){
        cout << "NO\n";
        cout << comp[1]+1 << " " << comp[0]+1;
    }
    else cout << "YES";

    return 0;
}