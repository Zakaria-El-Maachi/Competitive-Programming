#include <bits/stdc++.h>

using namespace std;

long long solve(int m, int a, int b, vector<vector<long long>> &d){
	while((1<<m) > (b-a+1)) m--;
	return min(d[m][a], d[m][b-(1<<m)+1]);
}

int main(){
	
	int n, q, m, a, b;
	cin >> n >> q;
	vector<int> v(n);
	m = 25;
	vector<vector<long long>> p(m+1, vector<long long>(n, 0));
	
	for(int i = 0; i < n; i++){
		cin >> v[i];
		p[0][i] = v[i];
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = 0; j+(1<<i) <= n; j++){
			p[i][j] = min(p[i-1][j], p[i-1][j+(1<<(i-1))]);
		}
	}
	for(int i = 0; i < q; i++){
		cin >> a >> b; a--; b--;
		cout << solve(m, a, b, p) << endl;
	}
	
	return 0;
}