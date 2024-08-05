#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> v(n);
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--; b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bool valid = true;
	queue<int> q;
	vector<int> t;
	t.assign(n, -1);
	
	for(int i = 0; i < n; i++){
		if(t[i] != -1) continue;
		t[i] = 0;
		q.push(i);
		
		while(!q.empty()){
			a = q.front();
			q.pop();
			for(int u : v[a]){
				if(t[u] == -1){
					t[u] = 1-t[a];
					q.push(u);
				}
				else{
					if(t[u] == t[a]){
						valid = false;
						goto end;
					}
				}
			}
		}
	}
	end:
	if (valid){
		for(int i = 0; i < n; i++) cout << t[i]+1 << " ";
	}
	else cout << "IMPOSSIBLE";
	
	
	return 0;
}