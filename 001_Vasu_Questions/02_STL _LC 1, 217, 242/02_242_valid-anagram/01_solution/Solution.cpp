/*

242. Valid Anagram
Easy
Topics
premium lock icon
Companies
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false
Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 
Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

*/

#include <bits/stdc++.h>
using namespace std;
bool isArgan(string s , string t){
  if(s.size() != t.size()){return false;}
  

  vector<int> count(26,0);
  for(int i = 0; i< s.size(); i++){
     count[s[i] - 'a'] = count[s[i] - 'a'] + 1;
            count[t[i] - 'a'] = count[t[i] - 'a'] - 1;
  }

  for(int i =0; i< 26 ;i++){
          if (count[i] != 0) {
                return false;
            }
  }

  return true;

}
int main(){

    cout << "============ ArgamChecker ===============" << endl;

    string s, t;

    cout << "Enter your First string" << endl;
    cin >> s;

    cout << "Enter the second string" << endl;
    cin >> t;

    bool result = isArgan(s, t);

    if(result){
        cout << "Anagram" << endl;
    }
    else{
        cout << "Not Anagram" << endl;
    }

    return 0;
}


