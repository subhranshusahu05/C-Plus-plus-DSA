/*

1281. Subtract the Product and Sum of Digits of an Integer
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an integer number n, return the difference between the product of its digits and the sum of its digits.
 

Example 1:

Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15
Example 2:

Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21


*/




#include<bits/stdc++.h>
using namespace std;

int SubPandS(int number)
{
    int sum =0;
    int product =1;

    while(number !=0){
        int digit = number%10;
        product = product*digit;
        sum = sum+ digit;
        number =number/10;


    }

    int answer = product- sum;


}
int main()
{

    cout<<"Enter your number"<<endl;

    int number;
     cin>> number;

     int result = SubPandS(number);
    
     cout<<result;

 


}
