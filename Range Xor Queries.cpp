#include <bits/stdc++.h>

using namespace std;

int t[800005];

void build(int a[200005], int v, int l, int r){
	if(l == r) t[v] = a[l];
	else{
		int m = (l+r)/2;
		build(a, v*2, l, m);
		build(a, v*2+1, m+1, r);
		t[v] = (t[v*2] ^ t[v*2+1]);
	}
}

int XOR(int v, int tl, int tr, int l, int r){
	if(l > r) return 0;
	if(l == tl && r == tr) return t[v];
	int tm = (tl + tr)/2;
	return (XOR(v*2, tl, tm, l, min(tm, r)) ^ XOR(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main(){
	
	int a[200005];
	int n, q, x, y;
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	build(a, 1, 0, n-1);
	
	for(int i = 0; i < q; i++){
		cin >> x >> y;
		cout << XOR(1, 0, n-1, x-1, y-1) << "\n";
	}
	
	return 0;
}