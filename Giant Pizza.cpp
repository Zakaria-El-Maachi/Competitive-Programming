#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> g, gr;
vector<bool> visited, ass;
vector<int> sorted, comp;

void dfs(int i){
    visited[i] = true;
    for(int j : g[i]){
        if(!visited[j]) dfs(j);
    }
    sorted.push_back(i);
}

void dfs(int i, int c){
    comp[i] = c;
    for(int j : gr[i]){
        if(comp[j] == -1) dfs(j, c);
    }
}

int main(){

    int n, m, a, x, y, nx, ny;
    char c;
    
    cin >> n >> m;

    g.resize(2*m); gr.resize(2*m); visited.assign(2*m, false); comp.assign(2*m, -1); ass.assign(m, false);

    for(int i = 0; i < n; i++){
        cin >> c >> a;
        a--;
        if(c == '+'){
            x = 2*a+1;
            nx = 2*a;
        } else{
            x = 2*a;
            nx = 2*a+1;
        }
        cin >> c >> a;
        a--;
        if(c == '+'){
            y = 2*a;
            ny = 2*a+1;
        } else{
            y = 2*a+1;
            ny = 2*a;
        }
        g[x].push_back(y);
        g[ny].push_back(nx);
        gr[y].push_back(x);
        gr[nx].push_back(ny);
    }

    for(int i = 0; i < 2*m; i++){
        if(!visited[i]) dfs(i);
    }

    reverse(sorted.begin(), sorted.end());


    int timer = 0;
    for(int i : sorted){
        if(comp[i] == -1) dfs(i, timer++);
    }

    for(int i = 0; i < m; i++){
        if(comp[2*i] == comp[2*i+1]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        else if(comp[2*i] > comp[2*i+1]) ass[i] = true;
    }


    for(bool t : ass){
        if(t) cout << "+ ";
        else cout << "- ";
    }

    return 0;
}