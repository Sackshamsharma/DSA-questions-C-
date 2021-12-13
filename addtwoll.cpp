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

Node* reverse(Node* head){
        Node* curr=head, *prev=NULL, *next=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node *h1=reverse(first);
        Node *h2=reverse(second);
        Node *res=new Node(-1);
        Node*temp=res;
        int carry=0;
        while(h1!=NULL || h2!=NULL){
            int d=carry;
            if(h1!=NULL){
                d+=h1->data;
                h1=h1->next;
            }
            if(h2!=NULL){
                d+=h2->data;
                h2=h2->next;
            }
            
            carry=d/10;
            temp->next=new Node(d%10);
            temp=temp->next;
        }
        if(carry!=0){
            temp->next=new Node(carry);
        }
        
        
        return reverse(res->next);
    }