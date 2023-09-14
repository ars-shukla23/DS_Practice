#include<iostream>


using namespace std;

class Node{
    int data;
    Node* next;
    public:
      Node(int val){
         data=val;
         next=NULL;

      }
  
   friend class LinkedList;

};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head=NULL;
    }
    void create_ll(int* arr,int n);
    void display_ll();

};

void LinkedList::create_ll(int* arr,int n){
  this->head=new Node(arr[0]);
  Node* p=this->head;
  for(int i=1;i<n;i++){
    p->next=new Node(arr[i]);
    //p->next->data=arr[i];
    p=p->next;
  }
  
  
}

void LinkedList::display_ll(){
    Node*p=this->head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }

}


int main(){
    LinkedList ll;
    int n;
    cout<<"Enter the number of elements you want in your LL:";
    cin>>n;
    int* arr=new int[n];
    cout<<"Go on entering your values:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll.create_ll(arr,n);
    ll.display_ll();



    return 0;
}