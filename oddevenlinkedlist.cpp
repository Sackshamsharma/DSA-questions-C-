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
 
 void rearrangeEvenOdd(Node *head)
    {
       Node* o=head;
       Node* e=head->next;
       Node*estart=head->next;
       while(o->next!=NULL && e->next!=NULL){
               o->next=e->next;
               o=o->next;

               e->next=o->next;
               e=e->next;
       }
       
       o->next=estart;
    }