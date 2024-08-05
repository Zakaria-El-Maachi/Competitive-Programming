#include <bits/stdc++.h>

using namespace std;

int const a = 1e9+7;
int n, m;
vector<int> arr;
int memo[100005][102];

int solve(int idx, int v){
	if(idx == n) return 1;
	if(memo[idx][v] != -1) return memo[idx][v];
	if(arr[idx] != 0){
		if(abs(arr[idx] - v) > 1) return 0;
		return solve(idx+1, arr[idx]);
	}
	int sum = 0;
	for(int k : {v-1, v, v+1}){
		if(k > 0 && k <= m){
			sum += solve(idx+1, k);
			sum %= a;
		}
	}
	return memo[idx][v] = sum;
}

int main(){
	memset(memo, -1, sizeof(memo));
	cin >> n >> m;
	arr.resize(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	int ans = 0;
	
	if(arr[0] == 0){
		for(int i = 1; i <= m; i++){
			ans += solve(1, i);
			ans %= a;
		}
		cout << ans;	
	} else cout << solve(1, arr[0]);
	
	
	return 0;
}