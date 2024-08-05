#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string s;
	map<char, int> m, n;
	stack<char> g;
	cin >> s;
	for(char i = 'A'; i < 'Z' + 1; i++) m[i] = 0;
	for(int i = 0; i < s.length(); i++) m[s[i]]++;
	
	for(pair<char, int> a : m){
		if(a.second %2 == 1) n[a.first] = a.second;
	}

	if(n.size() > 1) cout << "NO SOLUTION";
	else{
		for(pair<char, int> a : m){
			if(a.second %2 == 0){
				for(int i = 0; i <a.second/2; i++){
					cout << a.first;
					g.push(a.first);
				}	
			}
		}
		for(pair<char, int> a : n){
			for(int i = 0; i <a.second; i++) cout << a.first;
		}
		while(!g.empty()){
			cout << g.top();
			g.pop();
		}
	}
	
	return 0;
}