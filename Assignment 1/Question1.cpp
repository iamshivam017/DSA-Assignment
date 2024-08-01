#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;

    }
};
class Linkedlist{
    public:
    Node* head;
    Node* tail;
    int size;

    Linkedlist(){
        head=tail=NULL;
        size=0;

    }
    void insertAtTail(int val){
        Node* temp=new Node(val);
        if(size==0) head =tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
     void insertAtHead(int val){
        Node* temp=new Node(val);
        if(size==0) head = tail =temp;
        else{
            temp->next=head;

            head=temp;
        }
        size++;
    }
    void insertAtidx(int idx,int val){
        cout<<endl;
        if(idx<0 || idx>size) cout<<"invalid index"<<endl;
        else if(idx==0) insertAtHead(val);
        else if(idx==size) insertAtTail(val);
        else{
            Node* t=new Node(val);
            Node* temp=head;
            for(int i=1;i<=idx-1;i++){
                temp=temp->next;

            }
            t->next=temp->next;
            temp->next=t;
            size++;
        }
    }

    int getAtidx(int idx){
        if(idx<0||idx>=size){
            cout<<"invalid index";
            return -1;

        }
        else if(idx==0) return head->val;
        else if(idx==size-1) return tail->val;
        else {
            Node* temp=head;
            for(int i=1;i<=idx;i++){
                temp=temp->next;

            }
            return temp->val;
        }
    }

    void deleteAtHead(){
        if(size==0){
            cout<<"list is empty";
            return ;
        }
        head =head->next;
        size--;
    }
    void deleteAtTail(){
       if(size==0){
            cout<<"list is empty";
            return ;
        }
        Node* temp =head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
        size--;
    }
    void deleteAtIdx(int idx){

        if(size==0){
            cout<<"list is empty";
            return ;
        }
        else  if(idx<0|| idx>=size){
            cout<<"invalid index";
            return ;
        }
        else if(idx==0)return deleteAtHead();
        else if(idx==size-1) return deleteAtTail();
        else {
            Node* temp =head;
            for(int i=1;i<=idx;i++){
                temp=temp->next;

            }
            temp->next=temp->next->next;
            size--;
        }

    }

    int sizea(){
    int size =0;
    Node* trav = head;
    while(trav!=NULL){
        trav = trav->next;
        size++;
    }
    return size;
   }


   int middle() const{
   if(size==0){
            cout<<"list is empty";
            return 1 ;
        }
        // else  if(idx<0|| idx>=size){
        //     cout<<"invalid index";
        //     return ;
        // }

        Node* fast=head;
        Node* slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->val;
        cout<<endl;
   }
   void reverse(){
    cout<<endl;
   if(size==0){
            cout<<"list is empty";
            return  ;
        }
        Node* prev=NULL;
        Node* current=head;
        Node* next=NULL;
        while(current){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
   }
   void isempty(){
    if(size==0){
            cout<<"true";
        }
        else {
           cout<<"false";
        }
   }

   int indexOf(int val) {
    cout<<endl;
    Node* current =head;
    int index=0;
    while(current!=NULL){
        if(current-> val== val){
            return index;
        }
        current =current->next;
        index++;
    }
    return -1;
   }
   
   


          
      

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;

        }
        cout<<endl;
    }

};
int main(){
    Linkedlist ll;
    ll.insertAtTail(10);
    // ll.display();
    ll.insertAtTail(10);
    // ll.display();
    ll.insertAtTail(30);
    ll.insertAtTail(40);
    // ll.display();
    ll.insertAtHead(50);
    //  ll.display();
     ll.insertAtidx(3,78);
    //  ll.display();
    cout<< ll.getAtidx(2)<<endl;
    ll.deleteAtHead();
    // ll.display();
    ll.deleteAtTail();
    // ll.display();
    ll.display();
   
    cout<< ll.sizea()<<endl;
    cout<<ll.middle();
    ll.insertAtidx(3,88);
    ll.display();
    cout<<ll.middle();
    ll.reverse();
    ll.display();
    ll.isempty();
    cout<<ll.indexOf(2);
   





}