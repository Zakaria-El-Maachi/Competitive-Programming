#include <bits/stdc++.h>

using namespace std;

int visited[200005];
vector<vector<int>> g;
int ans;


void dfs(int i, int p){
    for(int j : g[i]){
        if(j == p) continue;
        dfs(j, i);
        if(!visited[j] && !visited[i]){
            visited[i] = visited[j] = true;
            ans++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b;
    cin >> n;

    g.resize(n);
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));

    ans = 0;
    dfs(0, 0);

    cout << ans << endl;

    return 0;
}