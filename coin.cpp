#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n;i++){
      cin >> a[i];
  }
  vector<int> dp(s + 1, 1e9);

  dp[0] = 0;
  for (int i = 1; i <= s;i++){
      for (int j = 0; j < n;j++){
        if(a[j] <= i){
            dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
      }
  }
  cout << (dp[s] < 1e9 ? dp[s] : -1) << endl;
  return 0;
}