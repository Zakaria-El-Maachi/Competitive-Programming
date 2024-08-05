#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, a;
	vector<bool> v;
	cin >> n;
	v.assign(n, false);
	for(int i = 1; i < n; i++){
		cin >> a;
		v[a-1] = true;
	}
	for(int i = 0; i < n; i++){
		if(!v[i]){
			cout << i+1;
			break;
		}
	}
	return 0;
}