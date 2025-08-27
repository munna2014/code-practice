#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll T;
  cin>>T;
  while(T--){
    int n, c=0;
	    string s;
	    cin>>n>>s;
	    
	    for (int i=0; i<n; i++) {
	        if (s[i] == s[i+1]) c++;
	    }
	    cout<<c<<endl;
	
  }
  return 0;
}