#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	set<int> s2;
	cin >> n;
	if(n%4 == 0 || n%4 == 3){
		cout << "YES" << endl;
		if(n%4 == 0){
			cout << n/2 << endl;
			for(int i = 1; i <= n/4; i++){
				cout << i << " " << n-i+1 << " ";
			}
			cout << endl << n/2 << endl;
			for(int i = n/4 + 1; i <= n/2; i++){
				cout << i << " " << n-i+1 << " ";
			}
		}
		else{
			cout << (n-1)/2 << endl;
			for(int i = 1; i <= (n-1)/4; i++){
				cout << i << " " << n-i << " ";
			}
			cout << n << endl << (n-1)/2 + 1 << endl;
			for(int i = (n-1)/4 + 1; i < (n-1)/2; i++){
				cout << i << " " << n-i << " ";
			}
			cout << (n-1)/2 << " " << (n+1)/2 << endl;
		}
		
	}
	else cout << "NO" << endl;
	
	return 0;
}