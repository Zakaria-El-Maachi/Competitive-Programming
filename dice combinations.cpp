#include <iostream>
#include <cstring>

using namespace std;

int memo[1000002];

unsigned long long solve(int k){
	if(memo[k] != -1) return memo[k];
	unsigned long long ans =  (solve(k-1) + solve(k-2) + solve(k-3) + solve(k-4) + solve(k-5) + solve(k-6)) % (1000000007);
	return memo[k] = ans;
}

int main(){
	
	int n;
	
	memset(memo, -1, sizeof(memo));
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 4;
	memo[4] = 8;
	memo[5] = 16;
	memo[6] = 32;
	
	cin >> n;
	cout << solve(n) << endl;
	
	return 0;
}