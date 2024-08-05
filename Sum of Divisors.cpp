#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n, d = 1, sum = 0, mod = 1e9+7;
    cin >> n;

    while(d*d < n) d++;
    d--;

    for(int i = 1; i <= d; i++){
        sum += 2 * i * (n/i);
        sum %= mod;
    }

    d++;
    if(d*d == n) sum += n;
    else d--;

    sum += (n-d);
    sum %= mod;

    cout << sum;

    return 0;
}