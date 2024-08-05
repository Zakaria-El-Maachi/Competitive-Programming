#include <bits/stdc++.h>

using namespace std;

struct seg{
    bool vertical;
    int x1, x2;
    double m, b;
    seg(int x, int y, int a, int c){
        x1 = x; x2 = a;
        if(x == a) vertical = true;
        else{
            vertical = false;
            m = (c-y)/(x2-x1);
            b = y-m*x;
        }
    }
    bool intersect(seg& other) const{
        if(vertical && other.vertical)
            return x1 == other.x1;
        if(vertical && !other.vertical)
            return 
    }
};

int main(){

    int t, a, b, c, d;
    vector<seg> segments;
    cin >> t;

    while(t--){
        segments.clear();
        for(int i = 0; i < 2; i++){
            cin >> a >> b >> c >> d;
            segments.push_back(seg(a, b, c, d));
        }



    }

    return 0;
}