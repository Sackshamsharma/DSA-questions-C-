#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;

    node(int x){
        data=x;
        next=NULL;

    }
};

  struct node *reverse (struct node *head, int k)
    { 
        node*curr=head,*prevfirst=NULL;
        bool isfirstpass=true;
        
        while(curr!=NULL){
            node*prev=NULL,*next=NULL,*first=curr;
            int count=0;
            while(curr!=NULL && count<k){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                count++;
            }
            if(isfirstpass){
                head=prev;isfirstpass=false;
            }
            else{
                prevfirst->next=prev;
            }
            prevfirst=first;
        }
    
        return head;
    }

 node *reverse (struct node *head, int k)
    { 
        node* curr=head,*prev=NULL,*next=NULL;
        int count=0;
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
             curr=next;
             count++;
        }
        
        if(next!=NULL){
            node*resthead=reverse(next,k);
            head->next=resthead;
        }
        return prev;
    }

node *reverse(struct node*head, int k){

}
