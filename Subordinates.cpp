#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
vector<int> d;

int dfs(int u)
{
    int res = 0;
    for (int v : g[u])
    {
        res += (1 + dfs(v));
    }
    return d[u] = res;
}

int main()
{

    int n, k;
    cin >> n;
    d.resize(n);
    g.resize(n);
    for (int i = 1; i < n; i++)
    {
        cin >> k;
        g[k - 1].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        cout << d[i] << endl;
    }

    return 0;
}