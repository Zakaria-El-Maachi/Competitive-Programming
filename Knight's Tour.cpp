#include <bits/stdc++.h>

using namespace std;

int hx[] = {2, -2, 2, -2, 1, -1, 1, -1};
int hy[] = {1, -1, -1, 1, 2, -2, -2, 2};
int board[8][8];

bool valid(int x, int y){
    if(x < 8 && x >= 0 && y < 8 && y >= 0) return true;
    return false;
}

int calculate(int x, int y){
    int count = 0;
    for(int i = 0; i < 8; i++){
        int nx = x + hx[i]; int ny = y+hy[i]; 
        if(valid(nx, ny) && board[nx][ny] == -1) count++;
    }
    return count;
}

bool dfs(int x, int y, int d){
    board[x][y] = d;
    if(d == 64) return true;
    vector<tuple<int, int, int>> moves;
    for(int i = 0; i < 8; i++){
        int nx = x + hx[i]; int ny = y+hy[i];
        if(valid(nx, ny) && board[nx][ny] == -1){
            moves.push_back({calculate(nx, ny), nx, ny});
            
        }
    }
    sort(moves.begin(), moves.end());
    for(auto e : moves){
        if(dfs(get<1>(e), get<2>(e), d+1)) return true;
    }
    board[x][y] = -1;
    return 0;
}

int main(){
    memset(board, -1, sizeof(board));
    int x, y;
    cin >> x >> y;

    dfs(y-1, x-1, 1);

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    return 0;
}