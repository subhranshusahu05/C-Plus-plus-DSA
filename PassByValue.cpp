#include<iostream>
using namespace std;

 int dosomething(int a)
 {

    cout<<a<<endl;
    a=a+5;
    cout<<a<<endl;
    a=a+5;
    cout<<a<<endl;


}



int main(){
  int a = 10;
  dosomething(a);

  cout<<a<<endl;
 return 0;

}