/*https://leetcode.com/problems/maximum-subarray/

53. Maximum Subarray
Medium
Topics
premium lock icon
Companies
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.




*/


#include <bits/stdc++.h>
using namespace std;

 int MaxSubArray(vector<int> nums){
        int sum = 0;
        int MAXI = INT_MIN;
        for(int i =0; i<nums.size();i++)
        {
            sum = sum + nums[i];
            if(sum > MAXI )
            {
                    MAXI = sum;
            }
            if(sum<0)
            {
                sum = 0;

            }



        }
        return MAXI;


}

int main(){

    cout<<"Enter the Array size"<<endl;
    int length;
    cin>>length;

    cout<<"Enter Your Array with size"<<length<<endl;
        vector<int> nums(length);
    for(int i=0; i< length;i++)
    {
            cin>>nums[i];

    }


    int result = MaxSubArray(nums);

    cout<< result;

  

    

}




