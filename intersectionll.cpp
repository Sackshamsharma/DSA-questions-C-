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

int intersectPoint(Node* head1, Node* head2)
{
    Node* curr1=head1;
    Node* curr2=head2;
    int count1=1,count2=1;
    while(curr1!=NULL){
       
        curr1=curr1->next;
         count1++;
    }
    
    while(curr2!=NULL){
        
        curr2=curr2->next;
        count2++;
    }
    
    int diff=abs(count1-count2);
    curr1=head1;curr2=head2;
    if(count1>count2){
        while(diff--){
            curr1=curr1->next;
        }
    }
    else{
        while(diff--){
            curr2=curr2->next;
        }
    }
    
    while(curr1 && curr2){
        if(curr1==curr2){
            return curr1->data;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return -1;
}

