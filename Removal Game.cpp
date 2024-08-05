#include <bits/stdc++.h>

using namespace std;

long long memo[5002][5002];
vector<long long> x;

long long solve(int i, int j, long long s)
{
    if (memo[i][j] != -1)
        return memo[i][j];
    if (i == j)
        return memo[i][j] = 0;
    long long res = min(solve(i + 1, j, s - x[i]), solve(i, j - 1, s - x[j - 1]));
    return memo[i][j] = s - res;
}

int main()
{
    memset(memo, -1, sizeof(memo));
    int n;
    long long s = 0;
    cin >> n;
    x.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        s += x[i];
    }

    cout << solve(0, n, s);

    return 0;
}