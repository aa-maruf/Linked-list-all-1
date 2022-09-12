#include <bits/stdc++.h>
using namespace std;

class Node{
public:
 int val;
  Node* next;
  Node(int val){
    this->val=val;
    next=NULL;
  }
};


void display(Node* n){

  while(n != NULL){
    cout<<n->val<<" ";
    n=n->next;
  }
  cout<<endl;
}

void insertAtHead(Node* &head,int val){

    Node* newNode =new Node(val);
    newNode->next=head;
    head=newNode;

}

void insertAtTail(Node* &head,int val){
  Node* new_value=new Node(val);
  if(head == NULL){
    head=new_value;
    return;
  }
  Node* temp=head;
  while(temp->next != NULL){
    temp=temp->next;
  }
  temp->next=new_value;
}


void  reversedListPrint(Node* &head){

    Node* temp=head;
    Node* prev=NULL;
    Node* prev2=NULL;
    int sz=0;

    ///getting no of element
    while(temp != NULL){
        prev2=temp;
        temp=temp->next;
        sz++;
    }
    sz--;
    while(sz--){
        temp=head;
        while( temp->next!=NULL){
                prev=temp;
                temp=temp->next;
            }
            temp->next=prev;        ///adding to last element next
            prev->next = NULL;      ///assingning null to the element before last element

    }
    head=prev2;
    display(head);

}





//void listInsert(Node* &head,int pos,int val){
//
//  if(pos == 0){
//    Node* prev_head=head;
//    head=new Node(val);
//    head->next= prev_head;
//    return;
//  }
//  Node* temp=head;
//  pos--;
//  for(int i=0;i<pos;i++){
//    temp=temp->next;
//  }
//  Node* Insert=new Node(val);
//  Node* save_node=temp->next;
//
//  temp->next=Insert;
//  Insert->next=save_node;
//}


//void listDelete(Node* &head,int pos){
//
//    if(pos == 0){
//        head=head->next;
//        return;
//    }
//    pos--;
//    Node* temp= head;
//    for(int i=0;i<pos;i++){
//        temp=temp->next;
//    }
//    Node* c= temp->next->next;
//    delete temp->next;
//    temp->next=c;
//
//}


int main() {
  Node* head=NULL;
  int val;
  char choice ='1';
  cout<<"Choice 1: Insertion at Head" <<endl<<"Choice 2: Insertion of Tail"<<endl<<"Choice 3: Exit"<<endl;
  while(choice =='1' || choice =='2'){
    cout<<"Enter value: ";
    cin>>val;
    if(choice == '1')
        insertAtHead(head,val);
    else if(choice == '2')
        insertAtTail(head,val);
    cout<<"Enter choice:  ";
    cin>>choice;

  }
  display(head);
  reversedListPrint(head);


  //int value,pos;
//  cout<<"Enter value: ";
//  cin>>value;

  //cout<<"Enter position: ";
  //cin>>pos;

  //listInsert(head,pos,value);
  //listDelete(head,pos);
  //display(head);
}
