
/*

Example 1:
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1 + 2 1 + 2 + 3 1 + 2 + 3 + 4 ]
Example 2:
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1 + 1 l + 1 + 1
Example 3:
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]









*/


#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    for(int i = 1; i < nums.size(); i++){
        nums[i] = nums[i] + nums[i-1];
    } 
    return nums;
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    // Create a vector of size n
    vector<int> nums(n);
    
    cout << "Enter " << n << " numbers: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i]; // Taking user input for each element
    }
    
    // Calculate running sum
    vector<int> result = runningSum(nums);
    
    // Print the output
    cout << "Running Sum: ";

    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;    
}