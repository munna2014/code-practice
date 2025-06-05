#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {

        int n, x, y, sum_1 = 0, sum_2 = 0;
        cin >> n >> x >> y;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum_1 = sum_1 + arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > y)
                arr[i] = arr[i] - y;
            else
            {
                arr[i] = 0;
            }
            sum_2 = sum_2 + arr[i];
        }
        if (sum_1 > (sum_2 + x))
            cout << "COUPON" << endl;
        else
            cout << "NO COUPON" << endl;
    }
    return 0;
}