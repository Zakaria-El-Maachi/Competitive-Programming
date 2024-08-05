#include <iostream>
#include <cstring>

using namespace std;

int n, x;
int arr[102], memo[1000002];
	
int solve(int rest){
	if(memo[rest] != -1) return memo[rest];
	unsigned long long k = 0;
	for(int i = 0; i < n; i++){
		if(rest >= arr[i]){
			k += solve(rest - arr[i]);
			k %= 1000000007;
		}
	}
	return memo[rest] = k;
}


int main(){
	
	memset(memo, -1, sizeof(memo));
	memo[0] = 1;
	
	cin >> n >> x;
	
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	cout << solve(x) << endl;
	
	return 0;
}