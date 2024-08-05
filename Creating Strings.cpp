#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string s;
	vector<string> v;
	cin >> s;
	bool t = true;
	sort(s.begin(), s.end());
	while(t){
		v.push_back(s);
		t = next_permutation(s.begin(), s.end());
	}
	
	cout << v.size() << endl;
	for(string i : v) cout << i << endl;
	
	return 0;
}