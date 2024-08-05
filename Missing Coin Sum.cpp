#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	long long s = 1;
	cin >> n;
	vector<int> v(n);
	
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++){
		if(s < v[i]){
			cout << s;
			return 0;
		}
		s += v[i];
	}
	
	cout << s;
	
	return 0;
}