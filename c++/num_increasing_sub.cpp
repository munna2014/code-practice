#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n; // Input size of array

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int dp[2515];
    memset(dp, -1, sizeof(dp));

    function<int(int)> lis = [&](int i) -> int
    {
        if (dp[i] != -1)
            return dp[i];
        int ans = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                ans = max(ans, lis(j) + 1);
            }
        }
        return dp[i] = ans;
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, lis(i));
    }

    cout << "Length of LIS: " << ans << endl;
    return 0;
}
