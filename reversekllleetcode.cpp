
//  * Definition for singly-linked list.
  struct ListNode {
int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    
    int len(ListNode* head){
        return  (head)?1+len(head->next):0;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int itr=len(head)/k;
        
        ListNode*H=nullptr,*T=nullptr,*prev=nullptr,*next=nullptr,*curr=head;
        
        while(itr--){
            
            for(int i=0;i<k;i++){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            
            if(H==nullptr){
                H=prev;
                T=head;
            }
            else{
                T->next=prev;
                T=head;
            }
            head=curr;
        }
        
        T->next=curr;
        return H;
    }
};