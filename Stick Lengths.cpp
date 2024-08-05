#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	long long sum = 0;
	cin >> n;
	vector<int> p(n);
	
	for(int i= 0; i < n; i++) cin >> p[i];
	sort(p.begin(), p.end());
	
	int i = 0, j = n-1;
	while(i < j){
		sum += p[j] - p[i];
		i++;
		j--;
	}
	
	cout << sum << endl;
	
	return 0;
}