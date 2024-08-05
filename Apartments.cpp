#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, m, k, s, p, ans = 0;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	s = 0; p = 0;
	
	while(s < n && p < m){
		if(abs(a[s] - b[p]) <= k){
			p++;
			s++;
			ans++;
		}
		else if(a[s] > b[p]) p++;
		else s++;
	}
	
	cout << ans;
	
	return 0;
}