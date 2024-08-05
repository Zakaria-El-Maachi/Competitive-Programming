#include <bits/stdc++.h>

using namespace std;

#define pii pair<long long, long long>
#define x first
#define y second

long long det(pii a, pii b){
    return a.x*b.y - a.y*b.x;
}

int main(){

    int n;
    cin >> n;
    vector<pii> points(n);

    for(pii& k : points) cin >> k.x >> k.y;

    long long sum = 0;
    for(int i = 0; i < n-1; i++) sum += det(points[i], points[i+1]);
    sum += det(points.back(), points.front());

    cout << abs(sum);

    return 0;
}