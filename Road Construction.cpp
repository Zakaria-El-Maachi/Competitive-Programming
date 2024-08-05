#include <bits/stdc++.h>

using namespace std;

vector<int> parent, ranks, comp;
int biggest = 1;

int getParent(int u){
    if(parent[u] == u) return u;
    return getParent(parent[u]);
}

int setUnion(int u, int v){
    u = getParent(u), v = getParent(v);
    if(ranks[u] < ranks[v]) swap(u, v);
    parent[v] = u;
    comp[u] += comp[v];
    if(ranks[u] == ranks[v]) ranks[u]++;
    return comp[u];
}

int main(){

    int n, m, a, b;
    cin >> n >> m;

    parent.resize(n); ranks.assign(n, 0); comp.assign(n, 1);

    for(int i = 0; i < n; i++) parent[i] = i;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        if(getParent(a) != getParent(b)){
            biggest = max(biggest, setUnion(a, b));
            n--;
        }
        cout << n << " " << biggest << "\n";
    }

    return 0;
}