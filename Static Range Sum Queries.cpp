#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, q, a, b;
	cin >> n >> q;
	vector<int> v(n);
	vector<long long> p(n);
	cin >> v[0];
	p[0] = v[0];
	for(int i = 1; i < n; i++){
		cin >> v[i];
		p[i] = p[i-1] + v[i];
	}
	for(int i = 0; i < q; i++){
		cin >> a >> b;
		a--; b--;
		if(a == 0) cout << p[b] <<"\n";
		else cout << p[b]-p[a-1] << "\n";
	}
	
	
	return 0;
}