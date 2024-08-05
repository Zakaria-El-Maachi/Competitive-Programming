#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k, a;
    cin >> n >> k;
    vector<int> t(n);
    string s;
    int ans = k;

    for(int i = 0; i < n; i ++){
        cin >> s;
        a = 0;
        reverse(s.begin(), s.end());
        for(int j = 0; j < k; j++) a += ((s[j] == '1') * (1 << j));
        t[i] = a;
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ans = min(ans, __builtin_popcount(t[i] ^ t[j]));
        }
    }

    cout << ans;

    return 0;
}