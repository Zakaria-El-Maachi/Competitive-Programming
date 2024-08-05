#include <bits/stdc++.h>

using namespace std;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, a, b;
	vector<vector<int>> g;
	vector<bool> visited;
	vector<int> d, p, k;
	queue<int> q;
	cin >> n >> m;
	g.resize(n); d.assign(n, 1000000); p.resize(n); visited.assign(n, false);
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		g[a-1].push_back(b-1); g[b-1].push_back(a-1);
	}
	
	q.push(0);
	p[0] = -1; d[0] = 0;
	visited[0] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i : g[v]){
			if(!visited[i]){
				q.push(i);
				visited[i] = true;
				p[i] = v;
				d[i] = d[v] + 1;
			}
		}
	}
	
	if(visited[n-1]){
		cout << d[n-1] + 1 << "\n";
		int u = n-1;
		while(u != -1){
			k.push_back(u);
			u = p[u];
		}
		reverse(k.begin(), k.end());
		for(int i : k) cout << i+1 << " ";
	}
	else {
		cout << "IMPOSSIBLE";
	}
	
	return 0;
}