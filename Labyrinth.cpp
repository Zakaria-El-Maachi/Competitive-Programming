#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
int hx[] = {0, 0, 1, -1};
int hy[] = {1, -1, 0, 0};
int dir[] = {1, 2, 3, 4};

int main(){

    int n, m;
    char c;
    pair<int, int> a, b, t;
    vector<vector<char>> g;
    cin >> n >> m;
    g.resize(n);


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c; g[i].push_back(c);
            if(c == 'A') a = {i, j};
            if(c == 'B') b = {i, j};
        }
    }

    queue<pair<int, int>> q;
    vector<bool> visited(m*n, false);
    vector<int> d(m*n, MAX), p(m*n, MAX);

    q.push(a);
    d[a.first*m + a.second] = 0;
    p[a.first*m + a.second] = 0;
    visited[a.first*m + a.second] = true;

    while(!q.empty()){
        t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = t.first + hx[i], ny = t.second + hy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(g[nx][ny] != '#' && !visited[nx * m + ny]){
                    d[nx * m + ny] = d[t.first*m + t.second] + 1;
                    p[nx * m + ny] = dir[i];
                    q.push({nx, ny});
                    visited[nx * m + ny] = true;
                }
                if(g[nx][ny] == 'B'){
                    while(!q.empty()) q.pop();
                    break;
                }
            }
        }
    }

    if(d[b.first * m + b.second] < MAX){
        cout << "YES" << endl << d[b.first * m + b.second] << endl;
        stack<int> s;
        t = b;
        while(p[t.first * m + t.second] != 0){
            int temp = p[t.first * m + t.second];
            s.push(temp);
            t = {t.first-hx[temp-1], t.second-hy[temp-1]};
        }
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            switch (temp)
            {
            case 1:
                cout << "R";
                break;
            case 2:
                cout << "L";
                break;
            case 3:
                cout << "D";
                break;
            case 4:
                cout << "U";
                break;
            }
        }
    } else{
        cout << "NO";
    }

    return 0;
}