#include <bits/stdc++.h>
using namespace std;
int main(){
//define 
vector<int> v;
v.push_back(1);
cout<<*v.begin()<< endl;

v.emplace_back(2);
cout<<*v.begin()+1<<endl;

for(auto i = v.begin(); i !=v.end(); i++){
    cout<<"for loop start"<<endl;
    cout<<*i<<endl;
    cout<<"for loop end"<<endl;
;

}

//pair vector
vector<pair<int,int>> vec;
vec.push_back({1,2});
vec.emplace_back(3,4);
for(auto o =vec.begin(); o !=vec.end();o++){
 cout << o->first << " " << o->second << endl;
}

//vector

vector<int> cc(5,100);
for(int num :cc){
cout<<num<<endl;
}


}