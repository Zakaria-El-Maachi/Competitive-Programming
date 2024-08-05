#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, x, r, a;
    cin >> n >> x;
    r = n/2;
    vector<int> t(n), suma, sumb;
    int ans = 0;

    for(int& i : t) cin >> i;

    for(int i=1; i < (1 << r); i++) {
        a = 0;
        for(int j = 0; j < r; j++)
            if((1 << j) & i) a += t[j];
        if(a == x) ans++;
        else suma.push_back(a);
    }

    for(int i=1; i < (1 << (n-r)); i++) {
        a = 0;
        for(int j = r; j < n; j++)
            if((1 << (j-r)) & i) a += t[j];
        if(a == x) ans++;
        else sumb.push_back(a);
    }

    sort(suma.begin(), suma.end());
    sort(sumb.begin(), sumb.end());

    for(int k: suma) {
        ans += upper_bound(sumb.begin(), sumb.end(), x-k) - lower_bound(sumb.begin(), sumb.end(), x-k);
    }

    cout << ans;

    return 0;
}