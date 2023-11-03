#include<iostream>
#include<vector>

using namespace std;

bool is_prime(int n){
  for(int i=2;i<n;i++){
    if(n%2==0){
        return false;
    }
  }
  return true;
}

vector<int> prime_factorization(int n){
    vector<int> vec;
    int count=0;
    for(int i=2;i<n;i++){
        if(is_prime(i)){
          vec.push_back(i);
        }
    }
    vector<int> vec2;
    int x=vec.at(count);
    while(n!=1 && x*x<=n){   //This(x*x<=n) improves time complexity. Reduces it from O(n) to O(sqrt(n)) Using the logic that Multiple of a number>=2*Number. Refer notes for further help
        while(n%vec.at(count)==0){
            n=n/vec.at(count);
            vec2.push_back(vec.at(count));
        }
        count++;
    }  
  return vec2;
}

int main(){
 int n;
 cout<<"Enter the value you want to perform prime factorization on:";
 cin>>n;
 vector<int> result=prime_factorization(n);
 vector<int>::iterator it=result.begin();
 cout<<"The prime factors of n are:";
 for(it;it!=result.end();it++){
    cout<<*it<<" ";
 }
 cout<<endl;


    return 0;
}