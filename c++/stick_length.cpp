#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  ll n;
  cin >> n;
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++)
  {
      cin >> v[i];
  }
  sort(v.begin(), v.end());
  ll avg = v[n / 2];

  ll res = 0;
  for (int i = 0; i < n; i++)
  {
      res += abs(v[i] - avg);
  }
  cout << res << endl;

  return 0;
}