#include <bits/stdc++.h>

using namespace std;

int main(){

    long long t, n, x;
    string s;
    cin >> t;
    char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<int> g(10, 0);
    for(int i = 0; i < t; i++){
        cin >> n;
        g.assign(10, 0);
        g[0] = 1;
        for(int j = 1; j < 10; j++){
            for(int c = 17; c > 0; c--){
                s = "";
                for(int k = 1; k <= c; k++) s += numbers[j];
                if(stoll(s) <= n){
                    g[j] = c;
                    break;
                }
            }
        }
        for(int c = 17; c > 0; c--){
            s = "1";
            for(int k = 1; k <= c; k++) s += '0';
            if(stoll(s) <= n){
                g[0] = c;
                break;
            }
        }
        for(int k : g) cout << k << " ";
        cout << endl;
    }

    return 0;
}