#include <iostream>

using namespace std;

#define MAX(a, b) (a > b) ? a : b

int main()
{

    // Jai Shri Ram

    int t;

    cin >> t;

    while (t--)

    {

        int n;

        cin >> n;

        int a[n];

        int max = 0;

        for (int i = 0; i < n; i++)

        {

            cin >> a[i];

            max = MAX(max, a[i]);
        }

        cout << max << endl;
    }

    return 0;
}
