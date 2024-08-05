#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, x;
	long long sum, ans;
	cin >> n >> x;
	sum = x; ans = x;
	for(int i = 1; i < n; i++){
		if (sum < 0) sum = 0;
		cin >> x;
		sum += x;
		ans = max(ans, sum);
	}
	
	cout << ans;
	
	return 0;
}