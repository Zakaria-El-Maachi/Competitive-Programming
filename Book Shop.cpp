#include <bits/stdc++.h>

using namespace std;


int main(){
	
	int n, x;
	vector<int> h, s;
	cin >> n >> x;
	h.resize(n); s.resize(n);
	for(int i = 0; i < n; i++) cin >> h[i];
	for(int i = 0; i < n; i++) cin >> s[i];
	
	vector<vector<int>> memo(n+1,vector<int>(x+1,0));
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= x; j++){
			memo[i][j] = memo[i-1][j];
			if(j >= h[i-1]) memo[i][j] = max(memo[i][j], memo[i-1][j-h[i-1]]+s[i-1]);
		}
	}
	cout << memo[n][x];
	
	return 0;
}