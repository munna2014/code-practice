// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// int main(){
//   ios_base::sync_with_stdio(false);cin.tie(NULL);
//  int j=0;
// string n,p;
// cin>>n;
// p.resize(n.size());
// for(int i= n.size()-1;i>=0;i--){
//      p[j]=n[i];
//       j++;
// }

// if(p==n) cout<<"True";

// else cout<<"False";

//   return 0;
// }


// class Solution {
//     public boolean isPalindrome(int x) {
//         // Negative numbers are not palindromes
//         if (x < 0) return false;

//         String s = String.valueOf(x); // Convert to String
//         int n = s.length(); // Get length of the String

//         for (int i = 0; i < n / 2; i++) {
//             // Check if characters from start and end are not equal
//             if (s.charAt(i) != s.charAt(n - i - 1)) return false;
//         }

//         // All checks passed, the number is a palindrome
//         return true;
//     }
// }
#include <iostream>
using namespace std;

int main()
{
     int n, num, digit, rev = 0;

     cout << "Enter a positive number: ";
     cin >> num;

     n = num;

     do
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);

     cout << " The reverse of the number is: " << rev << endl;

     if (n == rev and n > 0)  // Negative numbers are not palindromic
         cout << " The number is a palindrome.";
     else
         cout << " The number is not a palindrome.";

    return 0;
}
