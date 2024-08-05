#include <bits/stdc++.h>

using namespace std;

int t[3500000];
vector<int> salaries;
vector<int> coords;

int idx(int i){
    return lower_bound(coords.begin(), coords.end(), i) - coords.begin();
}

void build(int v, int tl, int tr){
    if(tl == tr) t[v] = salaries[tl];
    else{
        int tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        t[v] = t[2*v] + t[2*v+1];
    }
}

int sum(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r) return t[v];
    int tm = (tl + tr)/2;
    return sum(2*v, tl, tm, l, min(tm, r)) + sum(2*v+1, tm+1, tr, max(tm+1, l), r);
}

void update(int v, int tl, int tr, int pos, int inc){
    if(tl == tr) t[v] += inc;
    else{
        int tm = (tl+tr)/2;
        if(pos <= tm) update(2*v, tl, tm, pos, inc);
        else update(2*v+1, tm+1, tr, pos, inc);
        t[v] = t[2*v] + t[2*v+1];
    }
}

struct query{
    char c;
    int a, b;
    query(char g, int h, int j): c(g), a(h), b(j) {}
    query(){}
};

int main(){

    int n, q, a, b, len;
    char c;
    cin >> n >> q;
    vector<int> s(n);
    vector<query> queries(q);

    for(int i = 0; i < n; i++) {
        cin >> a;
        s[i] = a;
        coords.push_back(a);
    }

    for(int i = 0; i < q; i++) {
        cin >> c >> a >> b;
        queries[i] = query(c, a, b);
        if(c == '?') {
            coords.push_back(a);
        }
        coords.push_back(b);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    len = coords.size();

    salaries.assign(len, 0);
    for(int i : s) salaries[idx(i)]++;

    build(1, 0, len-1);

    for(query k: queries) { 
        if(k.c == '!'){
            update(1, 0, len-1, idx(s[k.a-1]), -1);
            update(1, 0, len-1, idx(k.b), 1);
            s[k.a-1] = k.b;
        }
        else {
            cout << sum(1, 0, len-1, idx(k.a), idx(k.b)) << "\n";
        }
    }

    return 0;
}