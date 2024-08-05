#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, m = 1, ans = 1;
	string a;
	cin >> a;
	
	for(int i = 1; i < a.size(); i++){
		if(a[i] == a[i-1]){
			m++;
			ans = max(ans, m);
		}
		else m = 1;
	}
	cout << ans << endl;
	return 0;
}