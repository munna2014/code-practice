#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    if (nums.empty())
    {
        cout << 0 << endl;
        return 0;
    }

    sort(nums.begin(), nums.end());
    
    int seq_length = 1, max_length = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
            continue;
        else if (nums[i] == nums[i - 1] + 1)
            seq_length++;
        else
            seq_length = 1;
        max_length = max(max_length, seq_length);
    }

    cout << "Longest consecutive sequence length: " << max_length << endl;

    return 0;
}
