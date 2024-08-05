#include <bits/stdc++.h>

using namespace std;

int n, mod = 2e9+14;
long long memo[501][63000];

long long solve(int i, int sum){
    if(i == n+1){
        if(sum == 0) return 1;
        return 0;
    }
    if(memo[i][sum] != -1) return memo[i][sum];
    long long k = solve(i+1, sum);
    if(sum >= i) k = (k+solve(i+1, sum-i))%mod;
    return memo[i][sum] = k;
}

int main(){
    memset(memo, -1, sizeof(memo));
    cin >> n;
    if((1+n)*n % 4 == 0) cout << solve(1, (1+n)*n/4)/2;
    else cout << 0;

    return 0;
}