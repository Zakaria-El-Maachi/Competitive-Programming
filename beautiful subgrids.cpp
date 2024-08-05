#include <bits/stdc++.h>

#pragma GCC target("popcnt")

using namespace std;

int main(){

    int n, q;
    bitset<3000> a;
    cin >> n;
    vector<bitset<3000>> t;
    string s;
    long long ans = 0;

    for(int i = 0; i < n; i++){
        cin >> s;
        a = bitset<3000>(s);
        if(a.count() < 2) continue;
        t.push_back(a);
    }

    for(int i = 0; i < t.size(); i++){
        for(int j = i+1; j < t.size(); j++){
            a = t[i]&t[j];
            q = a.count();
            ans +=  q*(q-1)/2;
        }
    }

    cout << ans;

    return 0;
}