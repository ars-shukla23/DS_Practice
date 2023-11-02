#include<iostream>

using namespace std;

int fibonacci(int n){
   if(n==1 || n==0){
    return n;
   }
   else{
     return (fibonacci(n-1)+fibonacci(n-2));
   }
}


int main(){
    int n;
    cout<<"Enter the number of terms you want to find the fibonacci sum of:";
    cin>>n;
    cout<<"The fibonacci sum of "<<n<<" terms is:"<<fibonacci(n);
    return 0;
}