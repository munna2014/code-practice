#include<bits/stdc++.h>
#include<math.h>
const int MOD = 1e9 + 7;
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> dp(n + 1);

  dp[0] = 1;
  for (int i = 1; i <= n;i++){
      for (int j = 1; j <= 6;j++){
        if(j <=i ){
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
      }
  }
  cout << dp[n] << endl;
  return 0;
}