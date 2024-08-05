#include <bits/stdc++.h>

using namespace std;

long long t[800005];

void build(int a[200005], int v, int l, int r){
	if(l == r) t[v] = a[l];
	else{
		int m = (l+r)/2;
		build(a, v*2, l, m);
		build(a, v*2+1, m+1, r);
		t[v] = 0;
	}
}


void update(int v, int tl, int tr, int l, int r, int add){
	if(l > r) return;
	else if(l == tl && r == tr) t[v] += add;
	else{
		int tm = (tl + tr)/2;
		update(v*2, tl, tm, l, min(tm, r), add);
		update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
	}
}

long long query(int v, int tl, int tr, int idx){
	if(tl == tr) return t[v];
	int tm = (tl + tr)/2;
	if(idx <= tm) return t[v] + query(v*2, tl, tm, idx);
	else return t[v] + query(v*2+1, tm+1, tr, idx);
}

int main(){
	
	int a[200005];
	int n, q, x, y, z, w;
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	build(a, 1, 0, n-1);
	for(int i = 0; i < q; i++){
		cin >> x;
		if(x == 1){
			cin >> y >> z >> w;
			update(1, 0, n-1, y-1, z-1, w);
		}
		else{
			cin >> y;
			cout << query(1, 0, n-1, y-1) << "\n";
		}
	}
	
	return 0;
}