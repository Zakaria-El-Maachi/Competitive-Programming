#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, a, b, c;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges(m);
    vector<long long> d(n, 1e18);
    vector<int> p(n, -1);
    d[0] = 0;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edges[i] = {c, {a-1, b-1}};
    }

    int x;
    for(int i = 0; i < n; i++){
        x = -1;
        for(auto e : edges){
            if(d[e.second.first] + e.first < d[e.second.second]){
                x = e.second.second;
                d[e.second.second] = d[e.second.first] + e.first;
                p[e.second.second] = e.second.first;
            }
        }
    }

    if(x == -1) cout << "NO";
    else{
        for(int i = 0; i < n; i++) x = p[x];
        vector<int> s;
        for(int v = x; ; v = p[v]){
            if(v == x && s.size() > 1) break;
            s.push_back(v);
        }
        cout << "YES\n";
        for(int k = s.size()-1; k >= 0; k--) cout << s[k] + 1 << " ";
        cout << s[s.size()-1] + 1;
    }

    return 0;
}