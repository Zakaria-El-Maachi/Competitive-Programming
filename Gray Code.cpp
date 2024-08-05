#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n; cin >> n;
	int m;
	vector<string> v;
	v.push_back("0");
	v.push_back("1");
	for(int i = 1; i < n; i++){
		m = pow(2, i);
		for(int j = 0; j < m; j++) v.push_back(v[m-j-1]);
		for(int j = 0; j < v.size()/2; j++) v[j] = "0" + v[j];
		for(int j = v.size()/2; j < v.size(); j++) v[j] = "1" + v[j];
	}
	
	for(string c : v) cout << c << endl;
	
	return 0;
}