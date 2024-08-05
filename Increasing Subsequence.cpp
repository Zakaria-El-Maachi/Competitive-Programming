#include <bits/stdc++.h>

using namespace std;

int main()
{

	int n;
	cin >> n;
	vector<int> x(n);

	for (int i = 0; i < n; i++)
		cin >> x[i];

	vector<int> l;
	l.push_back(x[0]);
	int d = 1;
	for (int i = 1; i < n; i++)
	{
		int pos = lower_bound(l.begin(), l.end(), x[i]) - l.begin();
		if (pos >= d)
		{
			d++;
			l.push_back(x[i]);
		}
		else
			l[pos] = x[i];
	}

	cout << d;

	return 0;
}