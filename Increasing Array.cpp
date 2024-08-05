#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, x0, x1, temp;
	long long sum = 0;
	cin >> n;
	cin >> x0;
	while(--n){
		cin >> x1;
		temp = max(0, x0-x1);
		sum += temp;
		x0 = x1 + temp;
	}
	cout << sum;
	
	return 0;
}