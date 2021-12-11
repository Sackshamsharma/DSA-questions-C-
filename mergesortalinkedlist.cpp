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
 
  Node* midpoint(Node*head){
        Node *slow=new Node(0);
        slow->next=head;
        Node *fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return slow;
    }
    
    Node * merge(Node *a, Node*b){
        if(a==NULL)return b;
        if(b==NULL)return a;
        Node* temp=new Node(-1);
        Node*head=temp;
        while(a!=NULL && b!=NULL){
            if(a->data<=b->data){
                temp->next=a;
                a=a->next;
                temp=temp->next;
                temp->next=NULL;
            }
            else{
                temp->next=b;
                b=b->next;
                temp=temp->next;
                temp->next=NULL;
            }
        }
        
        if(a!=NULL){
            temp->next=a;
        }
        else{
            temp->next=b;
        }
        return head->next;
    }
    
    Node* mergesort(Node*head){
        if(head==NULL || head->next==NULL)return head;
        Node *mid=midpoint(head);
        Node* head2=mid->next;
        mid->next=NULL;
        
        return merge(mergesort(head),mergesort(head2));
    }
    Node* mergeSort(Node* head) {
        // your code here
        return mergesort(head);
    }