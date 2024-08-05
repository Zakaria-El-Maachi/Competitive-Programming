#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, c = 5, count = 1, ans = 0;
	cin >> n;
	
	while(c <= n){
		ans += n/c;
		c *= 5;
		count++;
	}
	cout << ans;
	
	return 0;
}