#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> children;
vector<int> power;
vector<vector<int>> g;
long long bucket;

int dfs(int a){
    visited[a] = true;
    int c = 0;
    for(int b : g[a]){
        if(!visited[b]){
            c += dfs(b);
        }
    }
    if(g[a].size() > 1) return children[a] = c;
    else return children[a] = 1; 
}

void dfs2(int a, long long sum){
    visited[a] = true;
    if(a != 0 && g[a].size() == 1){
        bucket += sum;
    }
    for(int b : g[a]){
        if(!visited[b]){
            dfs2(b, sum + power[b]);
        }
    }
}

int main(){

    int t, n, a, b;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        g.clear();
        g.resize(n);
        children.resize(n);
        visited.assign(n, false);
        power.resize(n);
        for(int j = 0; j < n; j++){
            cin >> a;
            power[j] = a;
        }
        for(int j = 1; j < n; j++){
            cin >> a >> b;
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
        }
        if(n == 1){
            if(power[0] > 0) cout << power[0] << endl;
            else cout << 0 << endl;
        } else{
            dfs(0);
            bucket = 0;
            visited.assign(n, false);
            dfs2(0, power[0]);
            long long ans = 0;
            for(int j = 0; j < n; j++){
                if(power[j] < 0) ans = min(ans, (long long) children[j] * power[j]);
            }
            cout << bucket - ans << endl;
        }
    }

    return 0;
}