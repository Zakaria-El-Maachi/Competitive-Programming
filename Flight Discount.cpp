#include <bits/stdc++.h>
 
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, a, b, c;
	cin >> n >> m;
	vector<vector<pair<int, int>>> v(n), vi(n);
	vector<pair<int, pair<int, int>>> edges(m);
	
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		v[a-1].push_back({c, b-1});
		vi[b-1].push_back({c, a-1});
		edges[i] = {c, {a-1, b-1}};
	}
	
	vector<long long> d(n, 1e17), di(n, 1e17);
	priority_queue<pair<long long, int>> q;
	vector<bool> visited(n, false);
	q.push({0, 0});
	d[0] = 0;
	di[n-1] = 0;
	
	while(!q.empty()){
		int city = q.top().second;
		q.pop();
		if(visited[city]) continue;
		visited[city] = true;
		for(auto e : v[city]){
			if(d[e.second] > d[city] + e.first){
				d[e.second] = d[city] + e.first;
				q.push({-d[e.second], e.second});
			}
		}
	}
	q.push({0, n-1});
	visited.assign(n, false);

	while(!q.empty()){
		int city = q.top().second;
		q.pop();
		if(visited[city]) continue;
		visited[city] = true;
		for(auto e : vi[city]){
			if(di[e.second] > di[city] + e.first){
				di[e.second] = di[city] + e.first;
				q.push({-di[e.second], e.second});
			}
		}
	}

	long long ans = d[n-1];

	for(auto e : edges){
		int w = e.first;
		int u = e.second.first;
		int v = e.second.second;
		ans = min(ans, d[u] + di[v] + w/2);
	}
	
	cout << ans;

	return 0;
}