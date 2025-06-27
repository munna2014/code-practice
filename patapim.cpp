#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        map<int, int> mp;
        vector<int> b(2 * n + 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> b[i + j];
                mp[b[i + j]]++;
            }
        }
        for (int i = 1; i <= 2 * n; i++)
        {
            if (mp[i] == 0)
                b[1] = i;
        }
        for (int i = 1; i <= 2 * n; i++)
            cout << b[i] << " ";
        cout << endl;
    }
}