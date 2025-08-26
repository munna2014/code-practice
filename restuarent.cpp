#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  ll n;
  cin >> n;
  ll a, b, ans = 0, maxo = 0;
  map<ll, ll> m;
  for (ll i = 0; i < n; i++)
  {
      cin >> a >> b;
      m[a]++;
      m[b]--;
  }
  for (auto x : m)
  {
      ans += x.second;
      maxo = max(maxo, ans);
  }
  cout << maxo << endl;

  return 0;
}