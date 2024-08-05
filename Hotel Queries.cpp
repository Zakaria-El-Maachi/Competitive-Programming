#include <bits/stdc++.h>

using namespace std;

int h[200005], t[800005];

void build(int v, int l, int r){
    if(l == r) t[v] = h[l];
    else{
        int m = (l+r)/2;
        build(2*v, l, m);
        build(v*2+1, m+1, r);
        t[v] = max(t[2*v], t[2*v+1]);
    }
}

int hotel(int v, int l, int r, int num){
    if(t[v] < num) return -1;
    if(l == r) return l;
    int m = (l+r)/2;
    if(t[2*v] >= num) return hotel(2*v, l, m, num);
    return hotel(2*v+1, m+1, r, num);
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr) t[v] = val;
    else{
        int m = (tl+tr)/2;
        if(pos <= m){
            update(2*v, tl, m, pos, val);
        } else {
            update(2*v+1, m+1, tr, pos, val);
        }
        t[v] = max(t[2*v], t[2*v+1]);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, k, pos;
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> h[i];
    build(1, 0, n-1);
    for(int i = 0; i < m; i++){
        cin >> k;
        pos = hotel(1, 0, n-1, k);
        cout << pos+1 << " ";
        if(pos >= 0){
            update(1, 0, n-1, pos, h[pos]-k);
            h[pos] -= k;
        }
    }

    return 0;
}