#include <bits/stdc++.h>
using namespace std;

int hx[] = {1, -1, 0, 0};
int hy[] = {0, 0, 1, -1};
int dir[] = {1, 2, 3, 4};

int main(){

    int n, m;
    char a;
    pair<int, int> start, pos;
    vector<vector<char>> g;
    vector<int> visited, visited2;
    vector<int> p;
    queue<pair<int, int>> q;
    stack<int> s;
    cin >> n >> m;
    g.resize(n);
    visited.assign(n*m, 1e7); visited2.assign(n*m, 1e7);
    p.assign(n*m, -1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a;
            g[i].push_back(a);
            if(a == 'A') start = {i, j};
            else if(a == 'M'){
                q.push({i, j});
                visited[i*m + j] = 0;
            }
        }
    }
    
    if(start.first == 0 || start.second == 0 || start.first == n-1 || start.second == m-1){
        cout << "YES" << endl << 0 << endl;
        return 0;
    }

    while(!q.empty()){
        pos = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = pos.first + hx[i], ny = pos.second + hy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(g[nx][ny] != '#' && (visited[pos.first*m + pos.second] + 1) < visited[nx*m + ny]){
                    visited[nx*m + ny] = visited[pos.first*m + pos.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    q.push(start);
    visited2[start.first * m + start.second] = 0;


    while(!q.empty()){
        pos = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = pos.first + hx[i], ny = pos.second + hy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(g[nx][ny] != '#' && visited2[nx*m + ny] == 1e7 && visited[nx*m + ny] > visited2[pos.first*m + pos.second] + 1){
                    visited2[nx*m + ny] = visited2[pos.first*m + pos.second] + 1;
                    p[nx*m + ny] = dir[i];
                    q.push({nx, ny});
                    if(nx == 0 || ny == 0 || nx == n-1 || ny == m-1){
                        pair<int, int> t = {nx, ny};
                        while(t != start){
                            int temp = p[t.first*m + t.second];
                            s.push(temp);
                            t = {t.first - hx[temp-1], t.second - hy[temp-1]};
                        }
                        while(!q.empty()) q.pop();
                        break;
                    }
                }
            }
        }
    }

    if(s.size() > 0){
        cout << "YES" << endl << s.size() << endl;
        while(!s.empty()){
            switch (s.top())
            {
            case 1:
                cout << "D";
                break;
            case 2:
                cout << "U";
                break;
            case 3:
                cout << "R";
                break;
            case 4:
                cout << "L";
                break;
            }
            s.pop();
        }
    } else cout << "NO";

    return 0;
}