#include <iostream>
using namespace std;

int main() {
   int limit;
   cout<<"Enter the limiting value(number up to which we have to find all primes)";
   cin>>limit;
   bool a[limit+1];
    a[0]=false;
    a[1]=false;
   for(int i=2;i<limit+1;i++){
       a[i]=true;
   }
   for(int i=2;i<limit+1;i++){
       if(a[i]){
           for(int j=i;j<limit+1;j++){
               if(j%i==0 and j!=i){
                   a[j]=false;
               }
               else{
                   continue;
               }
           }
       }
   }
   
   for(int i=0;i<limit+1;i++){
       cout<<i<<" is "<<a[i]<<endl;
   }
    return 0;
}