#include <iostream>

using namespace std;

int main()
{

    int t, n, i;

    cin >> t;

    while (t--)
    {

        cin >> n;

        int a[n], b[n], count = 0;

        for (i = 0; i < n; i++)
        {

            cin >> a[i]; // distance alice ran on ith day
        }

        for (i = 0; i < n; i++)
        {

            cin >> b[i]; // distance bob ran on ith day
        }

        for (i = 0; i < n; i++)
        {

            if (a[i] <= 2 * b[i] && b[i] <= 2 * a[i])
                count++;

            // alice should run less than twice of bob's distance and so do bob should for both of them to be happy
        }

        cout << count << endl;
    }

    return 0;
}