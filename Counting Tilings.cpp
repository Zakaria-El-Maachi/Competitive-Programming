#include <bits/stdc++.h>

using namespace std;

int n, m, mod = 1e9+7, bitm = pow(2, 10) - 1;
int memo[1002][1500];

int solve(int i, int j){
    if(i == m){
        if(j == 0) return 1;
        return 0;
    }
    if(memo[i][j] != -1) return memo[i][j];

    int ans = 0;
    for(int k = 0; k < 10; k++){
        if(!(j & (1<<k))){
            ans += solve(i+1, );
        }
    }

    return memo[i][j] = ans;

    return ;
}

int main(){
    memset(memo, -1, sizeof(memo));
    cin >> n >> m;


    return 0;
}