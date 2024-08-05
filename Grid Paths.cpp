#include <bits/stdc++.h>

using namespace std;

int const m = 1e9+7;
int n;
bool valid[1002][1002];
int memo[1002][1002];


int solve(int x, int y){
	if(x == n-1 && y == n-1) return 1;
	if (memo[x][y] != -1) return memo[x][y];
	int sum = 0;
	if(x < n-1 && valid[x+1][y]) sum += solve(x+1, y)%m;
	if(y < n-1 && valid[x][y+1]) sum = (sum + solve(x, y+1))%m;
	return memo[x][y] = sum;
}

int main(){
	memset(memo, -1, sizeof(memo));
	cin >> n;
	char c;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> c;
			valid[i][j] = (c == '.')? true:false;
		}
	}
	
	if(!valid[0][0] || !valid[n-1][n-1]) cout << 0;
	else cout << solve(0, 0);
	
	return 0;
}