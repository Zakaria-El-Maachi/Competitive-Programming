#include <bits/stdc++.h>

using namespace std;

const int m = 1e9+7;

long long be(int n){
	if(n == 0) return 1;
	if(n == 1) return 2;
	long long a = be(n/2)%m;
	return ((a*a)%m * be(n%2)%m)%m;
}


int main(){
	
	int n;
	cin >> n;
	
	cout << be(n);
	return 0;
}