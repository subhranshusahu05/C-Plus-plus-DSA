#include<bits/stdc++.h>
using namespace std;

int NoOfBITS(int number)
{
    int count =0;
    while(number !=0){
        if(number&1){
            count++;
        }
        number = number>>1;
    }
    return count;

}


int main(){
    cout<<"Enter your Number"<<endl;
    int number ;
    cin>>number ;

    int result = NoOfBITS(number);
    cout<<"Then number of 1 bits in this is"<<number<<" "<<result;


}
