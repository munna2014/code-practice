#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        vector<pair<int,int>> vp;

        // Count frequency of each number
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        // Push frequency and number pairs into vector
        for(auto x : m) {
            vp.push_back({x.second, x.first});
        }

        // Sort by frequency descending
        sort(vp.rbegin(), vp.rend());

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(vp[i].second);
        }

        return res;
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements separated by spaces:\n";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k (number of top frequent elements to find): ";
    cin >> k;

    Solution solution;
    vector<int> result = solution.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements are: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
