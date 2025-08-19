#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n, x;
  cin >> n >> x;
  vector<int> val(n);
  vector<int> weight(n);

  for (int i = 0; i < n;i++){
      cin >> val[i];
  }

  for (int i = 0; i < n;i++){
      cin >> weight[i];
  }

  vector < vector<int>> dp(n + 1, vector<int>(x + 1));

  for (int i = 1; i <= n;i++){
      for (int j = 0; j <= x;j++){

          int w = weight[i - 1];
          int value = val[i - 1];

          int pick= (j >=i ? dp[i-1][j-w] + value : 0);
          int skip = dp[i - 1][j];

          dp[i][j] = max(pick, skip);
      }
  }

  cout << dp[n][x] << endl;
  return 0;
}