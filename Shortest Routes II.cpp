#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	
	const long long r = 1e17;
	int n, m, q, a, b, c;
	long long l;
	cin >> n >> m >> q;
	vector<vector<long long>> d(n, vector<long long>(n, r));
	
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		if(c < d[a-1][b-1]) d[a-1][b-1] = d[b-1][a-1] = c;
	}
	
	for(int i = 0; i < n; i++) d[i][i] = 0;
	
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	
	for(int i = 0; i < q; i++){
		cin >> a >> b;
		if(d[a-1][b-1] == r) cout << -1 << "\n";
		else cout << d[a-1][b-1] << "\n";
	}
	
	return 0;
}