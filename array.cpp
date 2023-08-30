#include<iostream>
#include<cmath>

using namespace std;

class Array{
  private:
       int *aptr;
       int size;
       int length;
  public:
   Array(){
    cout<<"Enter the size of your array:";
        cin>>size;
        cout<<"Enter the number of elements you want in your array:";
        cin>>length;
        aptr=new int[size];
   }
    
    
    void set_array(){
        
        cout<<"Enter your elements:\n";
        for(int i=0;i<length;i++)
           cin>>aptr[i];      
    }
    
    void display_array();
    void append_element(Array *p,int x);
    void insert_element(Array *p,int index,int x);
    int delete_element(Array *p,int index);
    int linear_search(Array p,int key);
    int binary_search(Array p, int key);
    int recur_binary(Array p,int l,int h,int key);
    int get(Array p,int index);
    void set(Array *p,int index,int value);
    int max(Array p);
    int min(Array p);
    int sum(Array p);
    int recur_sum(Array p,int n);
    void reverse(Array *p);
    void lshift(Array *p);
    void rshift(Array *p);
    void r_rotate(Array *p);
    void l_rotate(Array *p);
    bool is_sorted();
    void insert_at_sorted(Array *p,int x);
    void insert_at_sorted_2(Array *p,int x);
    void negative_num_on_left(Array *p);

    

};


void Array::display_array(){
    cout<<"The array elements are:";
    for(int i=0;i<length;i++){
            cout<<aptr[i]<<" ";
    }
    cout<<"\n";
    

}

void Array::append_element(Array *p ,int x){
     if(p->size>p->length){
        p->aptr[length]=x;
        p->length+=1;
     }
}

void Array::insert_element(Array *p,int index,int x){  
  if(index<p->length+1){      
    for(int i=p->length;i>index;i--){
        p->aptr[i]=p->aptr[i-1];
        }
    p->aptr[index]=x;  
    length++;
  }
  else{
    cout<<"Be mindful of array length"<<endl;
  }
}

int Array::delete_element(Array *p,int index){
   int num;
   if(index<p->length){
      num=p->aptr[index];
    for(int i=index;i<(p->length-1);i++){
      p->aptr[i]=p->aptr[i+1];

    }
    p->aptr[length-1]=0;
    p->length--;
   }
   return num;
}

int Array::linear_search(Array p,int key){
  bool found=false;
  for(int i=0;i<p.length;i++){
    if(p.aptr[i]==key){
      return i;
    }
   
  }
  return -1;
}

void Array::reverse(Array *p){
  int arr[p->length];
  for(int i=0;i<p->length;i++){
    arr[i]=p->aptr[(p->length)-i-1];
  }
  for(int i=0;i<p->length;i++){
    p->aptr[i]=arr[i];
  }
}

int Array::binary_search(Array p,int key){  
  bool found=false;           //Pre-requisite of binary search is that the array must be sorted
  int l=0;
  int h=(p.length)-1;
  int mid;
  while(l<=h ||p.aptr[mid]!=key){
        mid=floor((l+h)/2);
        if(p.aptr[mid]==key){
           return mid;
           
        }
        else if(key<(p.aptr[mid])){
           h=mid-1;
        }
        else if(key>(p.aptr[mid])){
            l=mid+1;
        }

  }
  return -1;
}

int Array::recur_binary(Array p,int l,int h,int key){
  if(l<=h){
    int mid=floor((l+h/2));
    if(p.aptr[mid]==key){
      return mid;
    }
    else if(key<p.aptr[mid]){
      return recur_binary(p,l,mid-1,key);

    }
    else if(key>p.aptr[mid]){
      return recur_binary(p,mid+1,h,key);
    }
  }
  return -1;
}

int Array::get(Array p,int index){
  return p.aptr[index];

}

void Array::set(Array *p,int index,int value){
  p->aptr[index]=value;

}

int Array::max(Array p){
  int max=p.aptr[0];
  for(int i=1;i<p.length;i++){
      if(p.aptr[i]>max){
        max=p.aptr[i];
      }
  }
 return max;
}

int Array::min(Array p){
  int min=p.aptr[0];
  for(int i=1;i<p.length;i++){
    if(p.aptr[i]<min)
       min=p.aptr[i];

  }
  return min;
}

int Array::sum(Array p){
  int sum=0;
  for(int i=0;i<p.length;i++){
    sum+=p.aptr[i];
  }
  return sum;
}

int Array::recur_sum(Array p,int n){
   int sum;
   if(n!=0){
      return recur_sum(p,n-1)+p.aptr[n-1];
   }
   return 0;
}

void Array::lshift(Array *p){
  for(int i=0;i<p->length-1;i++){
    p->aptr[i]=p->aptr[i+1];
  }
  p->aptr[(p->length)-1]=0;
}

void Array::rshift(Array *p){
  for(int i=p->length-2;i>-1;i--){
    p->aptr[i+1]=p->aptr[i];
  }
  p->aptr[0]=0;
}

void Array::l_rotate(Array *p){
  int v=p->aptr[0];
  for(int i=0;i<p->length-1;i++){
    p->aptr[i]=p->aptr[i+1];
   }
   p->aptr[p->length-1]=v;

}

void Array::r_rotate(Array *p){
  int v=p->aptr[p->length-1];
   for(int i=p->length-2;i>-1;i--){
    p->aptr[i+1]=p->aptr[i];
   }
   p->aptr[0]=v;
}

bool Array::is_sorted(){
  int l=0;
  for(int i=0;i<length-1;i++){
    if(aptr[i]>aptr[i+1])
       return false;  
  }
  return true;
     
}

void Array::insert_at_sorted(Array *p,int x){
  int pos;
  for(int i=0;i<p->length;i++){
    if(x<(p->aptr[i])){
      pos=i;
      break;
    }
  }
  for(int i=length-1;i>pos-1;i--){
    p->aptr[i+1]=p->aptr[i];

  }
   p->aptr[pos]=x;
   p->length++;
}

void Array::insert_at_sorted_2(Array *p,int x){
   int i=p->length-1;
   while(p->aptr[i]>x){
     p->aptr[i+1]=p->aptr[i];
     i--;
   }
   p->aptr[i+1]=x;
   p->length++;
}

void Array:: negative_num_on_left(Array *p){
  int *f=&(p->aptr[0]);
  int *l=&(p->aptr[p->length-1]);
  while(f<l){
  while(*f<0){
    f++;
  }
  while(*l>0){
    l--;
  }
    if(f<l){
        int temp;
        temp=*f;
        *f=*l;
        *l=temp;
    }
  }
}



int main(){
   Array A;
   A.set_array();
   A.display_array();
   //A.append_element(19);
   //A.insert_element(&A,2,23);
   //A.display_array();
   //A.append_element(&A,5);
   //int num;
   //num=A.delete_element(&A,2);
   //int n=A.binary_search(&A,7);
   //A.display_array();
   //cout<<"The value deleted is:"<<num;
   //A.linear_search(&A,10);
   //int n=A.recur_binary(&A,0,7,13);
   //cout<<n;
   //int max,min;
   //cout<<"The max element is: "<<A.max(A)<<endl;
   //cout<<"The min element is: "<<A.min(A)<<endl;
   //int sum;
   //cout<<"The sum of the elements of the array are: "<<A.recur_sum(A,4)<<endl;
   //A.reverse(&A);
   //A.rshift(&A);
   //A.r_rotate(&A);
   //A.display_array();
   //int n=A.is_sorted();
   //cout<<n;
   //A.insert_at_sorted_2(&A,10);
   //A.display_array();
   A.negative_num_on_left(&A);
   A.display_array();


   return 0;
}