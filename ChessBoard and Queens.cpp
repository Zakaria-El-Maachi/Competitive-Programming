#include <bits/stdc++.h>

using namespace std;

bool valid[8][8];
bool column[8], diag1[16], diag2[16];
int ans = 0;


void search(int y) { 
	if (y == 8) { 
		ans++; return;
	}
	for (int x = 0; x < 8; x++) {
		if (column[x] || diag1[x+y] || diag2[x-y+7] || !valid[x][y]) continue;
		column[x] = diag1[x+y] = diag2[x-y+7] = true; 
		search(y+1);
		column[x] = diag1[x+y] = diag2[x-y+7] = false;
	} 
}

int main(){
	
	memset(column, false, sizeof(column));
	memset(diag1, false, sizeof(diag1));
	memset(diag2, false, sizeof(diag2));
	string a;
	
	
	for(int i = 0; i < 8; i++){
		cin >> a;
		for(int j = 0; j < 8; j++){
			if(a[j] == '.') valid[i][j] = true;
				else valid[i][j] = false;
		}
	}
	
	search(0);
	cout << ans << endl;
	
}