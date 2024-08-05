#include <bits/stdc++.h>

using namespace std;

int div(int n){
    int count = 0, i =1;
    while(i*i < n){
        if(n%i == 0) count++;
        i++;
    }
    count *= 2;
    if(i*i == n) count++;
    return count;
}

int main(){
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        cout << div(x) << "\n";
    }

    return 0;
}