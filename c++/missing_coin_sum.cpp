#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> coins(n);
  for (int i = 0; i < n; i++)
  {
      cin >> coins[i];
  }

  sort(coins.begin(), coins.end());

  long long int target = 1; 
  for (int i = 0; i < n; i++)
  {
      
      if (coins[i] > target)
      {
          break;
      }

      target += coins[i];
  }

  cout << target << endl;

  return 0;
}