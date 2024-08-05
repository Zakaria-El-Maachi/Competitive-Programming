#include <bits/stdc++.h>

using namespace std;

int const m = 1e9 + 7;
int n, t;
int memo[1000005][2];

long long solve(int h, int t)
{
	if (memo[h][t] != -1)
		return memo[h][t];
	long long res;
	if (t == 0)
	{
		res = (solve(h - 1, 0) * 2 + solve(h - 1, 1)) % m;
	}
	else
	{
		res = (solve(h - 1, 0) + solve(h - 1, 1) * 4) % m;
	}
	return memo[h][t] = int(res);
}

int main()
{
	memset(memo, -1, sizeof(memo));
	memo[0][0] = 1;
	memo[0][1] = 1;
	memo[1][0] = 3;
	memo[1][1] = 5;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << (solve(n - 1, 0) + solve(n - 1, 1)) % m << "\n";
	}

	return 0;
}