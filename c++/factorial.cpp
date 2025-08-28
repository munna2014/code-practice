#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Factorial not defined for negative numbers." << endl;
    }
    else
    {
        long long factorial = 1; // Use long long for larger numbers
        for (int i = 1; i <= n; i++)
        {
            factorial *= i;
        }
        cout << "Factorial of " << n << " is " << factorial << endl;
    }

    return 0;
}
