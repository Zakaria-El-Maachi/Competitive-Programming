#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	long long s = 0, h, m;
	cin >> n;
	vector<int> v(n);
	
	for(int i  = 0; i < n; i++){
		cin >> v[i];
		s += v[i];
	}
	m = s;
	for(int i = 0; i < (1 << n)-1; i++){
		h = 0;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)) h += v[j];
		}
		m = min(m, abs(s-2*h));
	}
	
	cout << m;
	
	return 0;
}