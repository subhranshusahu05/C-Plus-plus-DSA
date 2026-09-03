// my code have problem in the time complexity



#include <bits/stdc++.h>
using namespace std;
bool  Duplicate_Checker(vector<int> &nums){
   unordered_set<int> seen;

        for(int n : nums) {

            if(seen.count(n)) {
                return true;
            }

            seen.insert(n);
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