#include<iostream>
#include<cmath>

using namespace std;


int magical_transformation(int n){
   int sum=0;
   int ph=n;
  while(n>9){
    sum=0;
   while(n>1){
    sum+=((int)floor(n))%10;
    n=n/10;
   }
   n=sum;
  }
  return sum;
}

int main(){
   int n;
   cout<<"Enter the number you want to find the magical transformation of:";
   cin>>n;
   int answer=magical_transformation(n);
   cout<<"The answer is:"<<answer;

    return 0;
}