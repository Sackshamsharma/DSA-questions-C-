#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;

    Node(int x){
        data=x;
        next=NULL;

    }
};

// using stack in t.c=O(n) and s.c=O(n)
void reorderList(ListNode* head) 
    {
    stack<ListNode* > st;
        ListNode* curr=head;
        
        int len=0;
        while(curr!=NULL){
            st.push(curr);
            curr=curr->next;
            len++;
        }
        
        ListNode*end;
        ListNode*next;
        curr=head;
        
        for(int i=0;i<len/2;i++){
            end=st.top();
            st.pop();
            next=curr->next;
            curr->next=end;
            end->next=next;
            curr=next;
        }
        curr->next=NULL;
    }


struct Node* reverse(struct Node *head)
    {
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        
        while( curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    
void reorderList(Node* head) {
    
    Node* slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* h1=head;
    Node*h2=slow->next;
        h2=reverse(h2);
    slow->next=NULL;

    
    Node* dummy =new Node(0);
    Node*curr=dummy;
    while(h1!=NULL || h2!=NULL){
        if(h1){
            curr->next=h1;
            curr=curr->next;
            h1=h1->next;
        }
        if(h2){
            curr->next=h2;
            curr=curr->next;
            h2=h2->next;
        }
    }
    
   head=dummy->next;
}
