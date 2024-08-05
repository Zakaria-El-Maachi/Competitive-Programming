#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, x, y, m, ans;
	bool t;
	cin >> n;
	vector<pair<int, int>> a(n);
	priority_queue<int> q;
	
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		a[i] = {x, y};
	}
	sort(a.begin(), a.end());
	
	q.push(-a[0].second); ans = 1, m = 1;
	for(int i = 1; i < n; i++){
		if(-a[i].first < q.top()){
			
		}
		ans++;
	}
	
	return 0;
}