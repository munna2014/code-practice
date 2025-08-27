#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll T;
  cin>>T;
  while(T--){

	int n, k;
	cin >> n >> k;
	for(int i = 0; i< n; i++) {
	    if(i!=k) cout << i <<' ';
	}
	if(k<n) cout << k ;
	cout <<"\n";
  }
  return 0;
}