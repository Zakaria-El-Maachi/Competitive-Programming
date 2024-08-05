#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, k = 0, sum = 0;
    cin >> n;
    vector<int> x(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sum += x[i];
    }

    vector<int> reachable(++sum, -1);
    reachable[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = x[i]; j < sum; j++)
        {
            if (reachable[j] == -1 && reachable[j - x[i]] > -1 && reachable[j - x[i]] < (i + 1))
            {
                k++;
                reachable[j] = i + 1;
            }
        }
    }

    cout << k << endl;

    for (int j = 1; j < sum; j++)
    {
        if (reachable[j] > -1)
            cout << j << " ";
    }

    return 0;
}