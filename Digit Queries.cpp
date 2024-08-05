#include <bits/stdc++.h>

using namespace std;

#define ll long long

int p;
ll prev, l, r; 

void f(ll n){
	l = 1;
	r = 9;
	prev = 0;
	p = 1;
	while(r < n){
		prev += p*r*10;
		p++;
		l = r+1;
		r = r*10 + 9;
	}
}

int main(){
	
	int q;
	ll k, mid;
	cin >> q;
	while(q--){
		cin >> k;
		f(k);
		while()	
	}
	
	return 0;
}