#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, k, a, b, c;
    long long l;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        g[a-1].push_back({c, b-1});
    }

    priority_queue<pair<long long, int>> q;
    vector<long long> d(n, 0);
    vector<long long> flights;

    q.push({0, 0});

    while(d[n-1] <k){
        l = -q.top().first;
        a = q.top().second;
        q.pop();
        if(d[a] == k) continue;
        d[a]++;
        if(a == n-1) flights.push_back(l);
        for(auto e : g[a]) q.push({-l-e.first, e.second});
    }
    

    sort(flights.begin(), flights.end());

    for(int i = 0; i < k; i++) cout << flights[i] << " ";

    return 0;
}