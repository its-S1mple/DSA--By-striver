// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void print(int i,int n){
    if(i>n)
    return;
    print(i+1,n);
    cout<< i <<endl;
}
int main() {
    // Write C++ code here
 int n;
 cin>>n;
 
 cout<< "****printing from N to 1 using backtracking****"<<endl;
 print(1,n);
    return 0;
}