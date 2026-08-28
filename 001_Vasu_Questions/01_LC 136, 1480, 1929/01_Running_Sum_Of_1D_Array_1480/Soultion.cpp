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