#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, x, y, m, ans = 1;
	cin >> n;
	vector<pair<int, int>> a(n);
	priority_queue<int> q;
	
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		a[i] = {x, y};
	}
	sort(a.begin(), a.end());
	
//	for(pair<int, int> p : a) cout << p.first << " " << p.second << endl;
	
	q.push(-a[0].second); m = 1;
	for(int i =1; i < n; i++){
		while(!q.empty() && -a[i].first < q.top()){
			q.pop();
			m--;
		}
		q.push(-a[i].second); m++;
		ans = max(ans, m);
	}
	
	cout << ans ;
	
	return 0;
}