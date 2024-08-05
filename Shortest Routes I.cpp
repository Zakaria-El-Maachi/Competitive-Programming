#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	
	int n, m, f, b, c;
	long long len;
	pair<long long, int> a;
	cin >> n >> m;
	vector<vector<pair<int, int>>> v(n);
	
	for(int i = 0; i < m; i++){
		cin >> f >> b >> c;
		v[f-1].push_back({c, b-1});
	}
	
	vector<long long> d(n, 1e17);
	set<pair<long long, int>> q;
	q.insert({0, 0});
	d[0] = 0;
	
	while(!q.empty()){
		a = *q.begin();
		q.erase(q.begin());
		len = a.first;
		c = a.second;
		if(d[c] != len) continue;
		for(pair<int, int> u : v[c]){
			if(d[u.second] > d[c] + u.first){
				q.erase({d[u.second], u.second});
				d[u.second] = d[c] + u.first;
				q.insert({d[u.second], u.second});
			}
		}
	}
	
	for(int i = 0; i < n; i++) cout << d[i] << " ";
	
	return 0;
}