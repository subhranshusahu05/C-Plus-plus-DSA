/*
https://leetcode.com/problems/contains-duplicate/description/

217. Contains Duplicate
Easy
Topics
premium lock icon
Companies
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true

 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109



*/
#include <bits/stdc++.h>
using namespace std;
bool  Duplicate_Checker(vector<int> &nums){
   for(int i = 0 ; i< nums.size();i++){
        int n = nums[i];
        for(int j= 0; j< nums.size();j++){
            if(nums[j] == n && i != j){ return true;}


        }
   }

   return false;
}


int main(){
    int l;
    cout<< "enter your vector length";
    cin>>l;
    
    vector <int> nums(l);
    cout<<"Enter your"<<l<<"Numbrs";

    for(int k=0;k<l;k++){
        cin>>nums[k];
    }

    bool result = Duplicate_Checker(nums);
    cout << boolalpha << result << endl;

    return 0;

}