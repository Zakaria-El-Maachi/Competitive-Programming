#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Data{
    int sum, pref;

    Data() {}
    Data(int s, int p): sum(s), pref(p) {} 

};

Data maked(int i){
    return Data(i, max(0LL, i));
}

Data combine(Data l, Data r){
    Data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    return res;
}

Data t[1000000];
int arr[200005];

void build(int v, int tl, int tr){
    if(tl == tr) t[v] = maked(arr[tl]);
    else{
        int tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        t[v] = combine(t[2*v], t[2*v+1]);
    }
}

Data query(int v, int tl, int tr, int l, int r){
    if(l > r) return maked(0);
    if(tl == l && tr == r) return t[v];
    int tm = (tl + tr)/2;
    return combine(query(2*v, tl, tm, l, min(tm, r)), query(2*v+1, tm+1, tr, max(tm+1, l), r));
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr) t[v] = maked(val);
    else{
        int tm = (tl+tr)/2;
        if(pos <= tm) update(2*v, tl, tm, pos, val);
        else update(2*v+1, tm+1, tr, pos, val);
        t[v] = combine(t[2*v], t[2*v+1]);
    }
}

signed main(){

    int n, q, a, b, c;
    cin >> n >> q;

    for(int i = 0; i < n; i++) cin >> arr[i];

    build(1, 0, n-1);

    for(int i = 0; i < q; i++){
        cin >> c >> a >> b;
        if(c == 1){
            update(1, 0, n-1, a-1, b);
        } else {
            cout << query(1, 0, n-1, a-1, b-1).pref << "\n";
        }
    }

    return 0;
}