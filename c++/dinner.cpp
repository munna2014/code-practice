#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll T;
  cin>>T;
  while(T--){
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    if(n%p==0){
        if(n/p*q==m){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
  }
  return 0;
}