/*

⁡⁢⁣⁣𝗤𝘂𝗲𝘀𝘁𝗶𝗼𝗻 𝟭⁡
⁡⁣⁢⁣Implement Stack using Queues⁡

https://leetcode.com/problems/implement-stack-using-queues/submissions/1341045692/
class MyStack {
public:
    queue<int>a;
    MyStack() {
        
    }
    
    void push(int x) {
        a.push(x);
        for(int i=0;i<a.size()-1;i++){
            a.push(a.front());
            a.pop();
        }
    }
    
    int pop() {
        int temp=a.front();
        a.pop();
        return temp;
    }
    
    int top() {
        return a.front();
    }
    
    bool empty() {
        return a.empty();
    }
};

⁡⁢⁣⁣ 𝗤𝘂𝗲𝘀𝘁𝗶𝗼𝗻 𝟮⁡

⁡⁣⁢⁣𝗜𝗺𝗽𝗹𝗲𝗺𝗲𝗻𝘁 𝗤𝘂𝗲𝘂𝗲 𝘂𝘀𝗶𝗻𝗴 𝗦𝘁𝗮𝗰𝗸𝘀⁡

https://leetcode.com/problems/implement-queue-using-stacks/submissions/1341049174/
 class MyQueue {
public:
 stack<int> st;
 stack<int> ht;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(st.size()>0){
            ht.push(st.top());
            st.pop();
        }
        int x=ht.top();
        ht.pop();

        while(ht.size()>0){
            st.push(ht.top());
            ht.pop();
        }
        return x;
    }
    
    int peek() {
         while(st.size()>0){
            ht.push(st.top());
            st.pop();
        }
          int x=ht.top();
            while(ht.size()>0){
            st.push(ht.top());
            ht.pop();
        }
        return x;

    }
    
    bool empty() {
        if(st.size()==0) return true;
        else return false;
    }
};

Question 3















⁡⁢⁣⁣𝗤𝘂𝗲𝘀𝘁𝗶𝗼𝗻 𝟱⁡
⁡⁣⁢⁣Design Linked List⁡

https://leetcode.com/problems/design-linked-list/submissions/1341050668/
class MyLinkedList {
private:

   struct node{
    int value;
    node* next=NULL;
    node(int val){
        value=val;
        next=nullptr;
    }
   };
   node* head;
   int size;

public:  
    MyLinkedList() {
       head=nullptr;
       size=0;

        
    }
    
    int get(int index) {
        if(index>=size||index<0){
            return -1;

        }
        else{
            node* currentnode=head; 
            for(int i=0;i<index;i++){
                currentnode=currentnode->next;

            } 
            return currentnode->value;
        }
    }
    
    void addAtHead(int val) {
       addAtIndex(0,val);

    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>size||index<0){
            return;
        }
        node* newnode =new node(val);
        node* currentnode =head;    
        if(index==0){
            newnode->next=head;
            head=newnode;
        }
        else{
             for(int i=0;i<index-1;i++){
                currentnode=currentnode->next;
            }
            newnode->next=currentnode->next;
            currentnode->next=newnode;
        }
        size++;

        // else if(index==0) addAtHead(val);
        // else if(index==size) addAtHead(val);
            
    }
    
    void deleteAtIndex(int index) {
        if(index>=size||index<0){
            return ;
        }
        else if(index==0){
            node* temp=head;
            head=head->next;
            delete temp;
        }
        else{
            node *currentnode =head;
            for(int i=0;i<index-1;i++){
                currentnode=currentnode->next;
            }
            node* nextnode=currentnode->next->next;
            delete currentnode->next;
            currentnode->next=nextnode;
        }
        size--;
    }
        ~MyLinkedList(){
        node* nodeDelete=head;
        while(nodeDelete!=nullptr){
            head=head->next;
            delete nodeDelete;
            nodeDelete=head;

        }
     }
};



⁡⁢⁣⁣𝗤𝘂𝗲𝘀𝘁𝗶𝗼𝗻 𝟲⁡

⁡⁣⁢⁣Online Stock Span ⁡
https://leetcode.com/problems/online-stock-span/submissions/1341052222/

class StockSpanner {
public:
    int index;
    stack<pair<int,int>> st;
    StockSpanner() {
        index =-1; 
        // st.clear();
    }
    
    int next(int price) {
        index+=1;
        int ans;
        while(!st.empty() && st.top().first<= price )
        {
            st.pop();
        }
        ans = index - (st.empty()? -1: st.top().second);
        st.push({price,index});
        return ans;
    }
};


⁡⁢⁣⁣Question 7⁡

⁡⁣⁢⁣Design a Stack With Increment Operation⁡
https://leetcode.com/problems/design-a-stack-with-increment-operation/submissions/1341055565/
class CustomStack {
    public:
    vector<int> stack;
    int len;

    CustomStack(int maxSize) {
        this->len=maxSize;
    }
    
    void push(int x) {
        if(stack.size()<len){
            stack.push_back(x);
        }
    }
    
    int pop() {
        if(stack.empty()) return -1;

        else{
            int temp=stack.back();
            stack.pop_back();
            return temp;
        }
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k && i<stack.size();i++){
            stack[i]+=val;
        }
    }
};




*/

