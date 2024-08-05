#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;
vector<int> s, r;

void dfs(int a, int p){
    s.push_back(a);
    visited[a] = true;
    for(int b : g[a]){
        if(!visited[b]){
            dfs(b, a);
        } else if(b != p && s.size() > 2){
            if(r.empty()){
                r.push_back(b);
                for(int i = s.size()-1; i >= 0; i--){
                    r.push_back(s[i]);
                    if(s[i] == b) break;
                }
            }
        }
    }
    s.pop_back();
}

int main(){
    bool truth = false;
    int n, m, a, b;
    cin >> n >> m;
    g.resize(n);
    visited.assign(n, 0);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            s.clear();
            r.clear();
            dfs(i, i);
            if(!r.empty()){
                truth = true;
                cout << r.size() << endl;
                for(int k : r) cout << k + 1 << " ";
                break;
            }
        }
    }

    if(!truth) cout << "IMPOSSIBLE";

    return 0;
}