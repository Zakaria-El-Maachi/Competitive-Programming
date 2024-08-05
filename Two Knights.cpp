#include <bits/stdc++.h>

using namespace std;

int calc(int x, int y){
	int c = 0;
	if(x-1 > 0){
		if(y-2 > 0) c++;
		if(y+2 <= x) c++;
		if(x-2 > 0){
			if(y-1 > 0) c++;
			if (y+1 <= x) c++;
		}
	}
	return c;
}

int calc2(int x, int y){
	int c = 0;
	if(x-1 > 0){
		if(y-2 > 0) c+=2;
		if(y+2 < x) c+=2;
		else if(y+2 == x) c++;
		if(x-2 > 0){
			if(y-1 > 0) c+=2;
			if (y+1 < x) c+=2;
			else if(y+1 == x) c++;
		}
	}
	return c;
}

int main(){
	
	long long n, a;
	vector<long long> arr;
	cin >> n;
	arr.push_back(0);
	cout << 0 << endl;
	for(int k = 2; k <= n; k++){
		a = 0;
		for(int i = 1; i < k-2; i++) a += calc(k, i);
		a *= 2;
		if(k-1 > 0){
			a += calc2(k, k-1);
			if(k-2 > 0){
				a += calc2(k, k-2);
			}
		}
		a += calc(k, k);
		arr.push_back(arr.back() + a);
		a = k*k;
		cout << a*(a-1)/2 - arr.back() << endl;
	}
	
	
	
	return 0;
}