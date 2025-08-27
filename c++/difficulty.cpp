#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll T;
  cin>>T;
  while(T--){
      int n, f = 0;
      cin >> n;
      int arr[n];
      for (int i = 0; i < n;i++){
          cin >> arr[i];
      }
      for (int i = 0; i < n-1;i++){
        if(arr[i]>arr[i+1]){
            f = 1;
            break;
        }
      }
      if(f==1)
          cout << "NO" << endl;
          else
              cout << "YES" << endl;
  }
  return 0;
}