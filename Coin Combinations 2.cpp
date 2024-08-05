#include <bits/stdc++.h>

using namespace std;

long long memo[1000002];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	const int m = 1e9+7;
	int n, x;
	int arr[102];
	memset(memo, 0, sizeof(memo));
	cin >> n >> x;
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	sort(arr, arr+n);
	memo[0] = 1;
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j <= x; j++){
			if(j-arr[i] >= 0){
				memo[j] += memo[j-arr[i]];
				if (memo[j] >= m) memo[j] %= m;
			}
		}
	}
	
	cout << memo[x] << endl;
	return 0;
}