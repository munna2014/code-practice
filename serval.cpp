#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        set<char> st;
        for (int i = 0; i < s.size();i++){
            st.insert(s[i]);
        }
        if(rev>s)
            cout << "YES" << endl;
        else if(st.size()>1 and k>0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
} 