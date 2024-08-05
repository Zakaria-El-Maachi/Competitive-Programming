#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, m, a;
	multiset<int>::iterator b;
	cin >> n >> m;
	multiset<int> h;
	
	for(int i = 0; i < n; i++){
		cin >> a;
		h.insert(-a);
	}
	for(int i = 0; i < m; i++){
		cin >> a;
		a *= -1;
		b = h.lower_bound(a);
		if (b == h.end()){
			cout << -1 << endl;
			continue;
		}
		cout << -(*b) << endl;
		h.erase(b);
	}
	
	return 0;
}