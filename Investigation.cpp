#include <bits/stdc++.h>

using namespace std;

#define pii pair<long long, int>

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, a, b, c, city, mod = 1e9+7;
    long long price, maximum = 1e17;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    vector<long long> d(n, maximum), flightsMin(n), flightsMax(n), num(n, 0);

    while(m--){
        cin >> a >> b >> c;
        g[a-1].push_back({c, b-1});
    }

    priority_queue<pii> pq;
    vector<bool> visited(n, false);
    pq.push({0, 0});
    d[0] = 0;
    num[0] = 1;
    flightsMin[0] = 0;
    flightsMax[0] = 0;

    while(!pq.empty()){
        city = pq.top().second;
        price = -pq.top().first;
        pq.pop();
        if(visited[city]) continue;
        visited[city] = true;
        for(auto e : g[city]){
            if(d[e.second] > d[city] + e.first){
                d[e.second] = d[city] + e.first;
                num[e.second] = num[city];
                flightsMin[e.second] = flightsMin[city] + 1;
                flightsMax[e.second] = flightsMax[city] + 1;
                pq.push({-d[e.second], e.second});
            }
            else if(d[e.second] == d[city] + e.first){
                num[e.second] = (num[e.second] + num[city])%mod;
                flightsMin[e.second] = min(flightsMin[e.second], flightsMin[city] + 1);
                flightsMax[e.second] = max(flightsMax[e.second], flightsMax[city] + 1);
            }

        }
    }

    cout << d[n-1] << " " << num[n-1] << " " << flightsMin[n-1] << " " << flightsMax[n-1];

    return 0;
}