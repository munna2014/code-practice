#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  long long n, x;
  cin >> n >> x;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++)
  {
      cin >> v[i];
  }
  sort(v.begin(), v.end(), greater<long long>());
  long long gondolas = 0;
  long long second = n - 1;
  for (long long i = 0; i <= second; i++)
  {
      if ((v[i] + v[second]) <= x)
      {
          second--;
          gondolas++;
      }
      else
      {
          gondolas++;
      }
  }
  cout << gondolas << endl;

  return 0;
}