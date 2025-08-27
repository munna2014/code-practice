#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    // Precompute which subsets can fit in one ride
    vector<bool> can_fit(1 << n, false);
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int total_weight = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                total_weight += w[i];
            }
        }
        can_fit[mask] = (total_weight <= x);
    }

    // DP: dp[mask] = minimum rides for subset represented by mask
    vector<int> dp(1 << n, INT_MAX);
    dp[0] = 0; // 0 rides needed for empty set

    for (int mask = 0; mask < (1 << n); mask++)
    {
        if (dp[mask] == INT_MAX)
            continue;

        // Try all subsets of remaining people
        int remaining = ((1 << n) - 1) ^ mask; // XOR to get complement

        for (int submask = remaining; submask > 0; submask = (submask - 1) & remaining)
        {
            if (can_fit[submask])
            {
                int new_mask = mask | submask;
                dp[new_mask] = min(dp[new_mask], dp[mask] + 1);
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}