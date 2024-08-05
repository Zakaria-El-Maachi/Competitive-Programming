#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int l1, l2;
int memo[5005][5005];

int solve(int i, int j)
{
    if (memo[i][j] != -1)
        return memo[i][j];
    int res = solve(i - 1, j - 1);
    if (s1[i] != s2[j])
    {
        res = min(res, solve(i, j - 1));
        res = min(res, solve(i - 1, j));
        res++;
    }
    return memo[i][j] = res;
}

int main()
{
    memset(memo, -1, sizeof(memo));

    cin >> s1 >> s2;
    l1 = s1.length();
    l2 = s2.length();
    bool f = true, t;
    if (s1[0] == s2[0])
    {
        memo[0][0] = 0;
        f = false;
    }
    else
        memo[0][0] = 1;
    t = f;
    for (int i = 1; i < l1; i++)
    {
        if (t && s1[i] == s2[0])
        {
            memo[i][0] = memo[i - 1][0];
            t = false;
        }
        else
            memo[i][0] = memo[i - 1][0] + 1;
    }
    for (int i = 1; i < l2; i++)
    {
        if (f && s1[0] == s2[i])
        {
            memo[0][i] = memo[0][i - 1];
            f = false;
        }
        else
            memo[0][i] = memo[0][i - 1] + 1;
    }

    cout << solve(l1 - 1, l2 - 1);

    return 0;
}