#include <bits/stdc++.h>

using namespace std;

void hanoi(int a, int b, int c, int n){
	if(n == 0) return;
	hanoi(a, c, b, n-1);
	cout << a << " " << c << "\n";
	hanoi(b, a, c, n-1);
}

int main(){
	
	int n;
	cin >> n;
	
	cout << (1<<n) - 1 << endl;
	hanoi(1, 2, 3, n);
	
	return 0;
}