#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll T;
  cin>>T;
  while(T--){
    ll n;
    cin>>n;
    string s,r;
    cin>>s;
    for (int i=0;i<n;i+=2){
        if(s[i]=='0' && s[i+1]=='0'){
        r=r+"A"; }
        else if(s[i]=='0' && s[i+1]=='1'){
        r=r+"T"; }
      else if(s[i]=='1' && s[i+1]=='0') {
      r=r+"C"; }
      else if(s[i]=='1' && s[i+1]=='1'){
      r=r+"G";
    }

    }
    cout<<r<<endl;
  }

  return 0;
}