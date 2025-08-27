#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll T;
  cin>>T;
  while(T--){
    string s;
    cin>>s;
    ll cnt=0;
    ll f=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
        {
            cnt++;
        }
        else cnt--;

        if (cnt ==0 && i!=s.size()-1){
            f=1;
            break;
        }
    }
      if(f==1) cout<<"YES\n";
      else cout<<"NO\n";
  }
  return 0;
}