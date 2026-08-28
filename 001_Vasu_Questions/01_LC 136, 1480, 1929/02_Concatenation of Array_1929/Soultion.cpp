/*
https://leetcode.com/problems/concatenation-of-array/
1929. Concatenation of Array

Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.

 

Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
Example 2:

Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
 

Constraints:

n == nums.length
1 <= n <= 1000
1 <= nums[i] <= 1000
 */
#include <bits/stdc++.h>
using namespace std;

//creating function
vector<int> ConCat(vector<int>& nums){
       int m = nums.size();
        vector<int> ans(2*m);

    for(int j = 0; j< m;j++){
     ans[j] = nums[j];
     ans[j+m] = nums[j]; 


    }
return ans;

}


int main(){


    int n;
     cout<<"Enter the size of your vector"<<endl;
     cin>>n;

     vector<int> nums(n);//create vector f size n;

     cout<<"Enter "<<n<<"Numbers";

     for(int i=0;i<n;i++){
        cin>>nums[i];
     }

     // calling the function

     vector<int> result=  ConCat(nums);


     cout<<"the result is..."<<endl;

     for( int X : result){
            cout<<X<<" ";
     }

    return 0;
}
