#include <bits/stdc++.h>

using namespace std;

int m = 1e9+7;

int bin(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    long long k = bin(a, b>>1);
    return (k*k)%m*bin(a, b&1)%m;
}

int bin1(int a, int b, int c){
    if(c == 0) return a;
    if(c == 1) return bin(a, b);
    long long k = bin1(a, b, c>>1);
    k = bin1(k, b, c>>1);
    return bin1(k, b, c&1);
}

int main(){
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    int n, a, b, c;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        cout << bin1(a, b, c) << "\n";
    }

    return 0;
}