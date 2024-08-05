#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    int n, d = 1, biggest = 1;
    cin >> n;
    vector<int> g(n);
    for(int& i : g){
        cin >> i;
        biggest = max(biggest, i);
    }    

    while(d*d <= biggest) d++;
    vector<int> divisors(biggest+1, 0);

    for(int i = 1; i < d; i++){
        for(int j : g){
            if(i*i <= j && j%i == 0){
                divisors[i]++;
                if(i*i != j) divisors[j/i]++;
            }
        }
    }

    for(int i = biggest; i >= 0; i--){
        if(divisors[i] > 1){
            cout << i;
            break;
        }
    }

    return 0;
}