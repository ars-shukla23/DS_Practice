#include<iostream>

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
    void linear_search(Array *p,int key);

};
void Array::display_array(){
    cout<<"The array elements are:";
    for(int i=0;i<length;i++)
            cout<<aptr[i]<<" ";
    

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

void Array::linear_search(Array *p,int key){
  bool found=false;
  for(int i=0;i<length;i++){
    if(p->aptr[i]==key){
      cout<<"The search was succesful and we found element "<<key<<" at index "<<i;
          found=true;
    }
   
  }
  if(found==false)
      cout<<"The search was unsuccessful";
}

int main(){
   Array A;
   A.set_array();
   //A.display_array();
   //A.append_element(19);
   //A.insert_element(&A,2,23);
   //A.display_array();
   //A.append_element(&A,5);
   //int num;
   //num=A.delete_element(&A,2);
   A.display_array();
   //cout<<"The value deleted is:"<<num;
   A.linear_search(&A,10);

   


   return 0;
}