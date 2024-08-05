#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, x, ans = 0;
	cin >> n >> x;
	vector<int> p(n);
	
	for(int i = 0; i < n; i++) cin >> p[i];
	
	sort(p.begin(), p.end());
	
	int i = 0, j = n-1;
	
	while(i < j){
		if (p[j] + p[i] > x){
			ans++;
		}
		else{
			ans++;
			i++;
		}
		j--;
	}
	if(i == j) ans++;
	
	cout << ans << endl;
	
	return 0;
}