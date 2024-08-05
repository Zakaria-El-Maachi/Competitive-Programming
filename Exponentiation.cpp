#include <bits/stdc++.h>

using namespace std;

int m = 1e9+7;

int bin(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    long long k = bin(a, b/2);
    return (k*k)%m*bin(a, b%2)%m;
}

int main(){

    int n, a, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << bin(a, b) << "\n";
    }

    return 0;
}