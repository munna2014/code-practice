#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 25e2 + 10;
int dp[N];
vector<int> a(N);


int lis(int i){
   if(dp[i] != -1)
       return dp[i];
    int ans = 1;
    for (int j = 0; j < i;j++){
        if(a[i]>a[j]){
            ans = max(ans, lis(j) + 1);
        }
    }
    return dp[i]=ans;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  memset(dp, -1, sizeof(dp));
  int n;
  cin >> n;
  for (int i = 0; i <= n;i++){
      cin >> a[i];
  }

  int ans = 0;
  for (int i = 0; i < n;i++){
      ans = max(ans, lis(i));
  }
  cout << ans << endl;
  return 0;
}