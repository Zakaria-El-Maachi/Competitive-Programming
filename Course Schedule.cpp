#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> visited;
vector<int> colored;
vector<int> ord;

void dfs(int v){
	visited[v] = true;
	for(int u : g[v]){
		if(!visited[u]) dfs(u);
	}
	ord.push_back(v);
}

bool dfs_2(int v){
	colored[v] = 1;
	for(int u : g[v]){
		if(colored[u] == 1) return true;
		else if(colored[u] == 0){
			if(dfs_2(u)) return true;
		}
	}
	colored[v] = 2;
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m, a ,b;
	bool h = true;
	cin >> n >> m;
	g.resize(n);
	colored.assign(n, 0);
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		g[a-1].push_back(b-1);
	}
	
	visited.assign(n, false);
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			if(dfs_2(i)){
				h = false;
				break;
			}
			else dfs(i);
		}
	}
	if(h){
		reverse(ord.begin(), ord.end());
		for(int i : ord) cout << i+1 << " ";
	}
	
	else cout << "IMPOSSIBLE" ;
	return 0;
}