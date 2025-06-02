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
    ll arr[n+10],v;
    for(int i=1; i<=n;i++){
        cin>>arr[i];
        arr[i]=abs(arr[i]);
        if(i==1){
            v=arr[i];
        }
    }
    sort(arr+1,arr+n+1);
    int f=0;
    for(int i=0;i<=(n+1)/2;i++){
        if(arr[i]==v){
                f=1;
                break;
        }
    }
    if(f==1 || (n%2==0 && arr[n/2+1]==v)){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
  }
  return 0;
}