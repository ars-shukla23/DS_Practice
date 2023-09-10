#include<iostream>
#include<cmath>
#include<vector>

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
        //cout<<"Enter the number of elements you want in your array:";
        //cin>>length;
        aptr=new int[size];
   }
    
    
    void set_array(){
        cout<<"Enter your array length:";
        cin>>length;
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
    void merging_in_order(Array p,Array q);
    void union_of_array(Array p,Array q);
    void intersection_of_array(Array p,Array q);
    void difference_of_array(Array p,Array q);
    int single_missing_in_sorted();
    vector<int> multiple_missing_in_sorted();
    vector<int> pair_of_elem_with_sum_k(int k);
    vector<int> multiple_missing_in_unsorted();

    

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

void Array::merging_in_order(Array p,Array q){ //Both arrays must be sorted to begin with for the function to work.(Important new logic here)
   

   int a=0,b=0,c=0;
   int m=p.length;
   int n=q.length;

   while(a<m && b<n){
   if(p.aptr[a]<q.aptr[b]){
    this->aptr[c]=p.aptr[a];
    c++;
    a++;
   }

   else if(q.aptr[b]<p.aptr[a]){
    this->aptr[c]=q.aptr[b];
    c++;
    b++;
   }

   }
   for(a;a<m;a++){
    this->aptr[c]=p.aptr[a];
    c++;
   }
   for(b;b<n;b++){
    this->aptr[c]=q.aptr[b];
    c++;
   }

   this->length=m+n;

   
}

void Array::union_of_array(Array p,Array q){
  int m=p.length;
  int n=q.length;
  int count=0;
  for(int i=0;i<m;i++){
    this->aptr[i]=p.aptr[i];
  }
  for(int i=0;i<n;i++){
    bool insert=true;
    for(int j=0;j<m;j++){
      if(q.aptr[i]==p.aptr[j]){
         insert=false;
         break;
      }
    }
    if(insert==true){
       this->aptr[m+count]=q.aptr[i];
       count++;
    }

  }
  this->length=m+count;

}

void Array::intersection_of_array(Array p,Array q){
 int m=p.length;
 int n=q.length;
 int count=0;

 for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
    if(q.aptr[i]==p.aptr[j]){
      this->aptr[count]=q.aptr[i];
      count++;
    }
  }
  
 }
 this->length=count;

}

void Array::difference_of_array(Array p,Array q){
 int m=p.length;
 int n=q.length;
 int count=0;
 bool insert=false;

 for(int i=0;i<m;i++){
  for(int j=0;j<n;j++){
    if(p.aptr[i]!=q.aptr[j]){
          
    }
  }
  
 }
 this->length=count;

}

int Array:: single_missing_in_sorted(){
  int n=this->length;
  int miss=0;
  int c=1;
  for(int i=0;i<n;i++){
    if(this->aptr[i]!=c){
      //miss=this->aptr[i];
      break;
      return c;
      
    }
    c++;

  }
   return c;

}

vector<int> Array::multiple_missing_in_sorted(){
  vector<int> missing_elements;
  int n=this->length;
  int* arr=new int[n];
  for(int i=0;i<n-1;i++){
    if((this->aptr[i+1])-(this->aptr[i])>1){
      int diff=(this->aptr[i+1])-(this->aptr[i]);
       for(int j=this->aptr[i];j<this->aptr[i]+diff-1;j++){
           missing_elements.push_back(j+1);
        
       }
    }
  }
  return missing_elements;
}

vector<int> Array::pair_of_elem_with_sum_k(int k){
  vector<int> pair_with_k_sum;
  int n=this->length;
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if((this->aptr[i]+this->aptr[j]==k) && (i!=j)){
             pair_with_k_sum.push_back(this->aptr[i]);
             pair_with_k_sum.push_back(this->aptr[j]);
             goto resumption;
        }
      }
  }
  resumption:
  return pair_with_k_sum;
}

vector<int> Array::multiple_missing_in_unsorted(){  //We are using hashing method here. Hence we are assuming that the first element is 1.
  vector<int>missing_unsorted;
  int max=0;
  int n=this->length;
  for(int i=0;i<n;i++){
    if(this->aptr[i]>max){
      max=this->aptr[i];
    }
  }


  int *arr=new int[max+1];
  arr[0]=1;
  for(int i=0;i<n;i++){
    arr[this->aptr[i]]=1;
    
  }

  for(int i=0;i<max+1;i++){
    if (arr[i]!=1){
      missing_unsorted.push_back(i);
    }
  }
  return missing_unsorted;
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
   //A.negative_num_on_left(&A);
   //A.display_array();
   //Array B;
   //B.set_array();
   //B.display_array();
   //Array C;
   //C.merging_in_order(A,B);
   //C.display_array();
   //C.difference_of_array(A,B);
   //C.display_array();

   /*
   vector<int> missing_elements=A.multiple_missing_in_sorted();
   vector<int>:: iterator it=missing_elements.begin();
   cout<<"The missing elements are:";
   for(it;it!=missing_elements.end();it++){
     cout<<*it<<" ";
   }
   */
   /*
   int sum;
   cout<<"Enter the sum value:";
   cin>>sum;
   vector<int> elements_with_sum_k=A.pair_of_elem_with_sum_k(sum);
   vector<int>::iterator it=elements_with_sum_k.begin();
   cout<<"The two elements with sum "<<sum<<" are: ";
   for(it;it!=elements_with_sum_k.end();it++){
      cout<<*it<<" ";
   }
   */
   vector<int> missing_unsorted=A.multiple_missing_in_unsorted();
   vector<int>::iterator it=missing_unsorted.begin();
   cout<<"The missing elements are:";
   for(it;it<missing_unsorted.end();it++){
    cout<<*it<<" "; 
   }



   return 0;
}