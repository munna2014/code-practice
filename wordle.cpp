#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll T;
  cin>>T;
  while(T--){
    string s,t,m;
    cin>>s>>t;
    for(int i=0;i<s.size();i++){
        if(s[i]==t[i]) m=m+"G";
        else m=m+"B";
    }
     cout<<m<<endl;
  }
  return 0;
}