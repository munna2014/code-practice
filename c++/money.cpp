#include<bits/stdc++.h>
using namespace std;
#define ll long long int


 void countNotes(int amount){
     vector<int> notes = {1000, 500, 100, 50, 10,5, 1};

     cout << "Currency count" << endl;
     for(int note : notes){
        if(amount >= note){
            int count = amount / note;
            cout << note << " " << count << endl;
            amount = amount % note;
        }
     }

     
}




int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int amount;
  cout << "Enter amount : "<< endl;
  cin >> amount;
  countNotes(amount);

  return 0;
}