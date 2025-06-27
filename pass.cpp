#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll T;
  cin>>T;
  while(T--){
      int n, x;
      cin >> n >> x;
      int arr[n];
      for (int i = 0; i < n;i++){
          cin >> arr[i];
      }
      sort(arr, arr + n);
      int pass = arr[n - x] - 1;

      cout << pass << endl;
  }
  return 0;
}