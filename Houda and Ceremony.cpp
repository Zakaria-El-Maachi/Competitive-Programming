#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, n, m, a, b, x;
    
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n >> m;
        priority_queue<pair<int, pair<int, int>>> edges;
        vector<bool> curr(n, false);
        for(int k = 0; k < m; k++){
            cin >> a >> b >> x;
            edges.push({-x, {a-1, b-1}});
        }
        if(n %2 != 0) cout << "Houda Can't do it" << endl;
        else{
            long long w = 0;
            int count = 0;
            while(!edges.empty()){
                if(count == n) break;
                if(curr[edges.top().second.first] == true || curr[edges.top().second.second] == true){
                    edges.pop();
                    continue;
                }
                cout << edges.top().second.first + 1 << " " << edges.top().second.second + 1 << endl;
                w -= edges.top().first;
                if(!curr[edges.top().second.first]){
                    curr[edges.top().second.first] = true;
                    count++;
                }
                if(!curr[edges.top().second.second]){
                    curr[edges.top().second.second] = true;
                    count++;
                }
                edges.pop();
            }
            if(count == n) cout << w << endl;
            else cout << "Houda Can't do it" << endl;
        }
    }

    return 0;
}