#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;
int main(){
     // 1. Start the stopwatch
    auto start = steady_clock::now();
 for(int i=1; i<=10000; i++){
   cout<<i<<endl;
 }
// 2. Stop the stopwatch
    auto stop = steady_clock::now();

    // 3. Calculate the difference in milliseconds
    auto duration = duration_cast<milliseconds>(stop - start);

    // 4. Print the total time
    cout << "\nTime taken: " << duration.count() << " ms" << endl;

    return 0;
}