#include <bits/stdc++.h>

using namespace std;

int memo[505][505];

int solve(int a, int b)
{
    if (memo[a][b] != -1)
        return memo[a][b];
    if (a == b)
        return memo[a][b] = 0;
    int res = solve(a, b - 1) + solve(a, 1);
    for (int i = 2; i <= b / 2; i++)
        res = min(res, solve(a, b - i) + solve(a, i));
    for (int i = 1; i <= a / 2; i++)
        res = min(res, solve(a - i, b) + solve(i, b));
    return memo[a][b] = ++res;
}

int main()
{
    memset(memo, -1, sizeof(memo));
    int a, b;
    cin >> a >> b;

    for (int i = 1; i <= a; i++)
        memo[i][1] = i - 1;
    for (int i = 1; i <= b; i++)
        memo[1][i] = i - 1;

    cout << solve(a, b);

    return 0;
}