#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> visited;

void dfs(int v){
	visited[v] = true;
	for(int u : g[v]){
		if(!visited[u]) dfs(u);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, s = 0, c = 0;
	vector<vector<char>> mp;
	
	cin >> n >> m;
	mp.resize(n);
	for(int i = 0; i < n; i++){
		mp[i].resize(m);
		for(int j = 0; j < m; j++){
			cin >> mp[i][j];
			if(mp[i][j] == '#') s++;
		}
	}
	g.resize(n*m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mp[i][j] == '.'){
				if(j>0 && mp[i][j-1] == '.') g[i*m+j].push_back(i*m+j-1);
				if(i>0 && mp[i-1][j] == '.') g[i*m+j].push_back((i-1)*m+j);
				if(j<m-1 && mp[i][j+1] == '.') g[i*m+j].push_back(i*m+j+1);
				if(i < n-1 && mp[i+1][j] == '.') g[i*m+j].push_back((i+1)*m+j);
			}
		}
	}
	
	visited.assign(n*m, false);
	for(int i = 0; i < n*m; i++){
		if(!visited[i]){
			dfs(i);
			c++;
		}
	}
	
	cout << c-s << endl;
	
	return 0;
}