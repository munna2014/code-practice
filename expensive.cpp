#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k = 0, x;
        string s;
        cin >> s;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                k++;
            else
            {
                x = i;
                break;
            }
        }
        for (int i = 0; i < x; i++)
        {
            if (s[i] != '0')
                k++;
        }
        cout << k << endl;
    }
    return 0;
}