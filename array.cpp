// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// int main(){
//   ios_base::sync_with_stdio(false);cin.tie(NULL);
//   ll T;
//   cin>>T;
//   while(T--){
//     int n,f=0;
//     cin>>n;
//     int m;
//     cin>>m;
//     int arr[n];
// for(int i=0;i<n;i++){
//     cin>>arr[i];
// }
//     for(int i=0; i<n;i++){
// if(arr[i]==m) f=1;
// break;
//     }
  
//   if(f==1) cout<<"YES"<<endl;
//   else cout<<"NO"<<endl;
//   return 0;
//   }
// }

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int N ,x;

	cin>>N>> x;

	

	int A[N];

	for(int i=0;i<N;i++){

	    cin>>A[i];

	}

	

	for(int i=0;i<N;i++){

	    if(x==A[i]){

	        cout<<"YES";

	        return 0;

	    }

	}

	cout<<"NO";

}

