#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int in[200005], out[200005], v[200005], t[400010];
long long s[2000005];
int counter = 0;

void dfs(int i, int p){
    in[i] = counter++;
    t[in[i]] = v[i];
    for(int j : g[i]){
        if(j != p) dfs(j, i);
    }
    out[i] = counter;
}

void build(int v, int l, int r){
    if(l == r) s[v] = t[l];
    else{
        int m = (l+r)/2;
        build(2*v, l, m);
        build(2*v+1, m+1, r);
        s[v] = s[2*v] + s[2*v+1];
    }
}

long long query(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r) return s[v];
    int tm = (tl+tr)/2;
    return query(2*v, tl, tm, l, min(tm, r)) + query(2*v+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int l, int r, int pos, int x){
    if(l == r) s[v] = x;
    else{
        int m = (l+r)/2;
        if(pos <= m) update(2*v, l, m, pos, x);
        else update(2*v+1, m+1, r, pos, x);
        s[v] = s[2*v] + s[2*v+1];
    }
}

int main(){

    int n, q, a, b, c;
    cin >> n >> q;
    g.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 1; i < n; i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    dfs(0, 0);
    build(1, 0, n-1);

    for(int i = 0; i < q; i++){
        cin >> c;
        if(c == 1){
            cin >> a >> b;
            update(1, 0, n-1, in[a-1], b);
        } else {
            cin >> a;
            cout << query(1, 0, n-1, in[a-1], out[a-1]-1) << "\n";
        }
    }

    return 0;
}