#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll T;
  cin>>T;
  while(T--){
    ll n,k;
    string s;
    cin>>n>>k>>s;
    ll c0=0,c1=0;
    for(auto x:s)
    if(x=='0')c0++;
    else c1++;
    ll d= abs(c0-c1)/2;
    if (k<d) cout<<"NO\n";
    else if( (k-d)%2==0) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}