#include <iostream>
#include <vector>
using namespace std;

int countWays(vector<int> &coins, int sum)
{
    // dp[i] represents number of ways to make sum i
    vector<int> dp(sum + 1, 0);
    dp[0] = 1; // One way to make sum 0 (take no coins)

    // For each coin denomination
    for (int coin : coins)
    {
        // Update dp array for all sums from coin to target sum
        for (int i = coin; i <= sum; i++)
        {
            dp[i] += dp[i - coin];
        }
    }

    return dp[sum];
}

int main()
{
    int n, sum;
    cout << "Enter number of coin types: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter target sum: ";
    cin >> sum;

    int result = countWays(coins, sum);
    cout << "Number of ways to make sum " << sum << ": " << result << endl;

    return 0;
}