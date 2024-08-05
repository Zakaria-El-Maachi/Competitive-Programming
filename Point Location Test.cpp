#include <bits/stdc++.h>

using namespace std;

#define pii pair<long long, long long>

long long cross(pii a, pii b){
    return a.first*b.second - a.second*b.first;
}

int main(){

    long long t, x1, y1, x2, y2, x3, y3, e;
    cin >> t;

    while(t--){
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        e = cross({x3-x1, y3-y1}, {x2-x1, y2-y1});
        if(e == 0) cout << "TOUCH\n";
        else if (e > 0) cout << "RIGHT\n";
        else cout << "LEFT\n";
    }

    return 0;
}