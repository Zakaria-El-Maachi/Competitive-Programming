#include <bits/stdc++.h>

using namespace std;

int g[200005], t[800005];

void build(int v, int l, int r){
    if(l == r) t[v] = 1;
    else{
        int m = (l+r)/2;
        build(2*v, l, m);
        build(2*v+1, m+1, r);
        t[v] = t[2*v] + t[2*v+1];
    }
}

int query(int v, int l, int r, int k){
    if(l == r) return r;
    int m = (l+r)/2;
    if(t[2*v] >= k) return query(2*v, l, m, k);
    else return query(2*v+1, m+1, r, k-t[2*v]);
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr) t[v] = val;
    else{
        int tm = (tl + tr)/2;
        if(pos <= tm) update(2*v, tl, tm, pos, val);
        else update(2*v+1, tm+1, tr, pos, val);
        t[v] = t[2*v] + t[2*v+1];
    }
}

int main(){

    int n, p, ans;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> g[i];

    build(1, 0, n-1);

    for(int i = 0; i < n; i++){
        cin >> p;
        ans = query(1, 0, n-1, p);
        cout << g[ans] << " ";
        update(1, 0, n-1, ans, 0);
    }

    return 0;
}