#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, ans = 1;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[--a[i]] = i;
	}
	for(int i = 1; i < n; i++){
		ans += b[i-1] > b[i];
	}
	cout << ans << endl;
	return 0;
}