#include <bits/stdc++.h>

using namespace std;
long long t[800005];

void build(int a[200005], int v, int l, int r){
	if(l == r) t[v] = a[l];
	else{
		int m = (l+r)/2;
		build(a, v*2, l, m);
		build(a, v*2+1, m+1, r);
		t[v] = t[v*2] + t[v*2+1];
	}
}

long long sum(int v, int tl, int tr, int l, int r){
	if(l > r) return 0;
	if(l == tl && r == tr) return t[v];
	int tm = (tl+tr)/2;
	return sum(v*2, tl, tm, l, min(tm, r)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int n){
	if(tl == tr) t[v] = n;
	else{
		int tm = (tl+tr)/2;
		if(pos <= tm) update(v*2, tl, tm, pos, n);
		else update(v*2+1, tm+1, tr, pos, n);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int main(){
	
	int a[200005];
	int n, q, x, y, z;
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	build(a, 1, 0, n-1);
	
	for(int i = 0; i < q; i++){
		cin >> x >> y >> z;
		if(x == 1) update(1, 0, n-1, y-1, z);
		else cout << sum(1, 0, n-1, y-1, z-1) << "\n";
	}
	
	return 0;
}