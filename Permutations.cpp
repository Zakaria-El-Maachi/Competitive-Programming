#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n; deque<int> t;deque<int>::iterator it;
	cin >> n;
	if(n == 1) cout << 1;
	else if(n <= 3) cout << "NO SOLUTION";
	else {
		t.push_back(2); t.push_back(4); t.push_back(1); t.push_back(3);
		for(int i = 5; i<= n; i+=2){
			t.push_back(i); t.push_front(i+1);
		}
		if(t.front() > n) t.pop_front();
		for(it = t.begin(); it != t.end(); it++) cout << *it << " ";
	}
	
	return 0;
}