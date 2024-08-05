#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

int n, x;
int arr[102], memo[1000002];

int solve(int rest){
	if(memo[rest] != -1) return memo[rest];
	int k = 1000002;
	for(int i = 0; i < n; i++){
		if(rest >= arr[i]) k = min(k, 1+solve(rest-arr[i]));
	}
	return memo[rest] = k;
}

int main(){
	
	memset(memo, -1, sizeof(memo));
	memo[0] = 0;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int ans = solve(x);
	if(ans > 1000000) ans = -1;
	cout << ans << endl;
	
	return 0;
}