#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll T;
  cin>>T;
  while(T--){
      int n;
      cin >>n;
      int like[n], com[n];
      int mx_like = -1;
      for (int i = 0; i < n;i++){
          cin >> like[i];
          mx_like = max(like[i], mx_like);
      }
      for (int i = 0; i < n;i++){
          cin >> com[i];
      }
      int mx_cmnt = -1;
      int ans_in =- 1;

      for (int i = 0; i < n;i++){
        if(like[i]==mx_like){
            if(com[i]>mx_cmnt){
                ans_in = i;
                mx_cmnt = com[i];
            }
        }
      }
      cout << ans_in + 1 << endl;
  }
  return 0;
}