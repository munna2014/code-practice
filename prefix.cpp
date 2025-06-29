// class Solution
// {
// public:
//     string longestCommonPrefix(vector<string> &strs)
//     {
//         if (strs.empty())
//             return "";
//         string prefix = strs[0];
//         for (string s : strs)
//             while (!s.starts_with(prefix))
//                 prefix.pop_back();
//         return prefix;
//     }
// };
