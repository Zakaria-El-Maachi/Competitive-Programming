#include <iostream>
#include <cstring>

using namespace std;

int n;
char arr[1000][1000];
int memo[1002][1002];

int solve(int x, int y){
	
}

int main(){
	
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) cin >> arr[i][j];
	}
	
	cout << solve(0, 0) << endl;
	
	return 0;
}