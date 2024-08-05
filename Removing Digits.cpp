#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

int main(){
	
	int n, d, h;
	unsigned long long ans = 0;
	int arr[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
	cin >> n;
	
	while(n != 0){
		d = 1;
		for(int i = 1; i <= 6; i++){
			h = (n - (int) (n/arr[i] * arr[i])) / arr[i-1];
			d = max(d, h);
		}
		n -= d;
		ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}