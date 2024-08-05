#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> g;

void dfs(int y){
    visited[y] = true;
    for(int x : g[y]){
        if(!visited[x]) dfs(x);
    }
}

int main(){

    int n, m, a, b, c;
    long long inf = 1e17;
    vector<pair<int, pair<int, int>>> edges;
    vector<long long> d;
    cin >> n >> m;
    
    d.assign(n, inf);
    d[0] = 0;
    edges.resize(m);
    g.resize(n);
    visited.assign(n, false);

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edges[i] = {-c, {a-1, b-1}};
        g[b-1].push_back(a-1);
    } 

    bool t;

    for(int i = 0; i < n-1; i++){
        t = false;
        for(pair<int, pair<int, int>> e : edges){
            a = e.second.first; b = e.second.second; c = e.first;
            if(d[a] >= inf) continue;
            if(d[b] > d[a] + c){
                t = true;
                d[b] = d[a] + c;
            }
        }
        if(!t) break;
    }

    if(!t) cout << -d[n-1];
    else {
        vector<int> changed;
        bool t2 = false;
        for(pair<int, pair<int, int>> e : edges){
            a = e.second.first; b = e.second.second; c = e.first;
            if(d[a] >= inf) continue;
            if(d[b] > d[a] + c){
                changed.push_back(b);
                d[b] = d[a] + c;
            }
        }
        if(changed.size() > 0){
            dfs(n-1);
            for(int i : changed){
                if(visited[i]){
                    t2 = true;
                    break;
                }
            }
            if(t2) cout << -1;
            else cout << -d[n-1]; 
        }
        else cout << -d[n-1];
    }

    return 0;
}