#include<iostream>


using namespace std;

void right_triangle(int n){
  for(int i=1;i<n+1;i++){
    for(int j=0;j<i;j++){
         cout<<"*";
    }
     cout<<endl;
  }
}

void left_triangle(int n){
  for(int i=1;i<n+1;i++){
    for(int j=0;j<n-i;j++){
       cout<<" ";
    }
    for(int j=0;j<i;j++){
       cout<<"*";
    }
    cout<<endl;
  }
}

void full_triangle(int n){
  for(int i=1;i<n+1;i++){
    for(int j=0;j<n-i;j++){
       cout<<" ";
    }
    for(int j=0;j<i;j++){
       cout<<"*";
    }
    for(int j=0;j<i;j++){
         cout<<"*";
    }
    cout<<endl;
  }

}


int main(){
  int n;
  cout<<"Enter the number n:";
  cin>>n;
   //right_triangle(n);
   full_triangle(n);


    return 0;
}