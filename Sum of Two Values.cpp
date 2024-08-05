#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	map<int, int> s;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s[a[i]] =  i+1;
	}
	
	for(int i = 0; i < n; i++){
		if(s.find(x-a[i]) != s.end() && s[x-a[i]] != i+1){
			cout << i+1 << " " << s[x-a[i]] ;
			goto end;
		}
	}
	cout << "IMPOSSIBLE";
	end:
	return 0;
}